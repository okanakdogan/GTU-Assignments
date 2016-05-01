# Okan Akdogan 25/02/2016


# tool functions

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

#load leaf data
leaf_data <- read.table('leaf.dat',header = FALSE)

#Prepare Datas

normalize <- function(x){ 
  num <- x - min(x) 
  denom <- max(x) - min(x) 
  return (num/denom) 
}


#LEAF PROCESS

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


makeSVMTest <- function(data,labels){
  
  #Create 10 equally size folds
  folds <- cut(seq(1,nrow(data)),breaks=5,labels=FALSE)
  
  #Perform 5 fold cross validation with Euclidean and Manhattan distances
  
  #needs lib install with
  #> install.packages("e1071")
  
  library(e1071)
  
  
  for(i in 1:5){
    #Segement your data by fold using the which() function 
    testIndexes <- which(folds==i,arr.ind=TRUE)
    testData <- data[testIndexes, ]
    test_Labels <- labels[testIndexes]
    trainData <- data[-testIndexes, ]
    train_Labels <- labels[-testIndexes]
    
    svm.model <- svm(trainData,train_Labels)
    
    poly_svm.model <- svm(trainData,train_Labels,kernel = 'polynomial',degree = 2)
    #print(svm.model)
    pred <- predict(svm.model,testData)
    
    conf <- table(test_Labels,pred)
    
    pred_poly <- predict(poly_svm.model,testData)
    
    
    conf_poly <- table(test_Labels,pred_poly)
    
    
    #print(conf)
    #print(conf_poly)
    
    print(confMatrixMulti(conf))
    print(confMatrixMulti(conf_poly))
  }

}

makeSVMTest(norm_iris,label_iris)
makeSVMTest(norm_leaf,label_leaf)