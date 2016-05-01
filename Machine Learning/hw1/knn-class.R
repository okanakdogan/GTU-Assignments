
# Okan Akdogan 23/02/2016


#distance funcs for use in my knn implementation

euclid_dist <- function(p1,p2){
  
  if (length(p1)!=length(p2))
    return(-1)
  sum_sq <- 0
  for (i in 1:length(p1)) {
    sum_sq <- sum_sq + (p1[i]-p2[i])^2
  }
  return(as.numeric( sqrt(sum_sq)))
}

manhattan_dist <- function(p1,p2){
  if (length(p1)!=length(p2))
    return(-1)
  sum_sq <- 0
  for (i in 1:length(p1)) {
    sum_sq <- sum_sq + abs(p1[i]-p2[i])
  }
  return(as.numeric( sqrt(sum_sq)))
  
}

# knn implementation

myknn <- function(train,trainlabels,k,test,dist_func){
  
  #create dump vector to store result
  results <- c(1:as.numeric(nrow(test)))
  
  # for all test input
  for(t in 1:nrow(test)){
    
    # distance matrix to hold min k distances
    dist_mat <- matrix(data=Inf,k,2)
    
    #init matrix index column
    for(i in 1:k)
      dist_mat[i,2] <- 0
    
    # calculate in all train data
    for (v_ind in 1:nrow(train)) {
      # calc distance
      dist<- dist_func(train[v_ind,],test[t,])
      
      # check if you put in distance matrix
      # matrix holds min values distances and ther indicies
      for(i in 1:k){
        if (dist_mat[i,1] > dist ){
          dist_mat[i,1] <-dist
          dist_mat[i,2] <-v_ind
          break
        }
      }
    }
    
    #match min distance indicies with their labels
    res <- c(1:k) #empty vec
    
    for(i in 1:k){
      res[i]<- trainlabels[dist_mat[i,2]]
    }
    
    #table for see to frequency of labels
    res_t <- table(res)
    #select max frequency label
    results[t] <-as.numeric( names(which.max(res_t)))
  }
  #return all test results
  return(results)
}

#load leaf data
leaf_data <- read.table('leaf.dat',header = FALSE)

#Prepare Datas

normalize <- function(x){ 
  num <- x - min(x) 
  denom <- max(x) - min(x) 
  return (num/denom) 
}


#LEAF PROCESS
#load leaf data
leaf_data <- read.table('leaf.dat',header = FALSE)

#shuffle
shuffle_leaf <- leaf_data[sample(nrow(leaf_data)),]

#normalize
norm_leaf <- as.data.frame(lapply(shuffle_leaf[2:16], normalize))
label_leaf <- shuffle_leaf[,1]
summary(norm_leaf)


#IRIS PROCESS

#Randomly shuffle the data
shuffle_iris<-iris[sample(nrow(iris)),]

# normalize iris data
norm_iris <- as.data.frame(lapply(shuffle_iris[1:4], normalize))
label_iris <- shuffle_iris[,5]
summary(norm_iris)


testWith_5_CrossValid <- function( data, labels){
  
  #Create 5 equally size folds
  folds <- cut(seq(1,nrow(data)),breaks=5,labels=FALSE)
  
  #Perform 5 fold cross validation with Euclidean and Manhattan distances
  
  # hold funcnumber for print
  fnum <- 0
  
  for(f in c(euclid_dist,manhattan_dist)){
    fnum<-fnum+1
    
    if(fnum==1){
      print("knn with Euclidean Distance")
    }else{
      print("knn with Manhattan Distance")
    }
    
    for(i in 1:5){
      #Segement your data by fold using the which() function 
      testIndexes <- which(folds==i,arr.ind=TRUE)
      testData <- data[testIndexes, ]
      test_Labels <- labels[testIndexes]
      trainData <- data[-testIndexes, ]
      train_Labels <- labels[-testIndexes]
      
      system.time( myknn_res <- myknn(train=trainData,trainlabels = train_Labels,k=5,dist_func = f,test =testData))
      #print(myknn_res)
      # conf matrix
      conf <-table(test_Labels,myknn_res)
      
      cat("cross valid fold:",i,"\n")
      #print(conf)
      print(confMatrixMulti(conf))
      
    }
  }
}
confMatrixMulti <- function( confTable){
  
  confs <- matrix(data=NA, nrow = nrow(confTable),ncol = 4 )
  
  for (r in 1:nrow(confTable)) {
    
    TP <- 0
    FP <- 0
    
    for (c in 1:ncol(confTable)) {
      
      if( r==c )
        TP <- TP + confTable[r,c]
      else 
        FP<- FP + confTable[r,c]
      
    }
    confs[r,1]=TP
    confs[r,2]=FP
  }
  
  for (r in 1:nrow(confs)) {
    
    TN <- 0
    FN <- 0
    for (or in 1:nrow(confs)) {
        if(r==or){
            #skip for this row
        }else{
            TN <- TN + confs[or,1]
            FN <- FN + confs[or,2]
        }
    }
    confs[r,3] <- TN
    confs[r,4] <- FN
  }
  
  colnames(confs) <- c('TP','FP','TN','FN') 
  return(confs)
}

#test starts here

testWith_5_CrossValid(norm_iris,label_iris)
testWith_5_CrossValid(norm_leaf,label_leaf)

print("Code ends here")
