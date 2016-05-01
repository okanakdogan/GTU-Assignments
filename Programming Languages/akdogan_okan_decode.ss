
;; Okan Akdogan 121044017

;; contains "ctv", "vtc",and "reduce" definitions
(load "include.ss")

;; contains a test document consisting of a number of paragraphs. 
(load "document.ss")

;; contains a test-dictionary, which has a much smaller dictionary for testing
;; the dictionary is needed for spell checking
(load "test-dictionary.ss")

;; (load "dictionary.ss") ;; the real thing with 18,000 words


;; -----------------------------------------------------
;; HELPER FUNCTIONS

;; *** YOUR CODE FOR ANY HELPER FUNCTION GOES HERE ***

;;encode a paragraph
;;INPUT: a document "p" and a "encoder"
;;OUTPUT: an encoded paragraph using a provided encoder
(define encode-p;;this encoder is supposed to be the output of "encode-n"
  (lambda (p encoder)
    ;;'SOME_CODE_GOES_HERE ;; *** FUNCTION BODY IS MISSING ***
    (if (null? p)
      '()
        (cons (encoder (car p)) (encode-p (cdr p) encoder) ))
    ))

;;checks words in paragraph with spell-checker
;;INPUT: a paragraph "p"
;;OUTPUT: a list which contains boolean results.
(define checker-p 
  (lambda (p)
      (map spell-checker p)
    ))

;;checks document( group of paragraph) with checker-p
;;INPUT: a document "l"
;;OUTPUT: a list which contains check results' list
(define checker-pList
  (lambda (l)
      (map checker-p l)
    )
  )
;;converts boolean to values #t=1 and #f=0
;;INPUT: a list contains boolean symbols "l"
;;OUTPUT: a list contains 1 and 0s
(define btov
  (lambda (l)
    (if (null? l)
      '()
    (cons (if (car l) 1 0) (btov (cdr l)))
    )))
;;converts a list of lists which contains bool symbols,boolean to value
;;INPUT: a list of lists "l"
;;OUTPUT: a list of lists with values 
(define btov-l
  (lambda (l)
    (map btov l)
    ))

;;encodes a parapgraph with all possible shift values
;;INPUT: paragraph "p" and start value to 23 "n"
;;OUTPUT: a document contains shifted paragraphs
(define encode-all-possible
  (lambda (p n)
    (if (equal? n 24)
      '()
      (cons (encode-p p (encode-n n)) (encode-all-possible p (+ n 1))))
    ))
;;recudes a list of lists
;;INPUT: list of lists like '((1 0 1 1)(0 1 0 0))
;;OUTPUT: list of reduced with sum of values like (3 1)
(define reduce-l
  (lambda(l)
    (map (lambda(m) (reduce + m 0)) l)
    ))

;;gives reduced value list which created from encoded paragraph
;;INPUT: paragraph "p"
;;OUTPUT: a list of values
(define give-reduced-l
  (lambda (p)
      
        (define all-possible (encode-all-possible p 1))
        (define checked-l (checker-pList all-possible))
        (define value-l (btov-l checked-l))
        (reduce-l value-l)
        )
    )
;;finds index of a value in a list
;;INPUT: search value "value" and list "l"
;;OUTPUT: index of value
(define index
  (lambda (value l)
    (if (equal? (car l) value) 0 (+ 1 (index value (cdr l))))))

;;returns a procedure counts occurence of value in list
;;INPUT: value to search "v", list "l"
;;OUTPUT: number of occurence
(define count-occ 
  (lambda (v)
    (lambda (l)
    (if (null? l)
      0
      (if (equal? v (car l))
        (+ 1 ((count-occ v) (cdr l)))
        ((count-occ v) (cdr l)))
    )
  )))

;;counts occurence value in paragraph
;;INPUT: value "v",paragraph that contains words "p"
;;OUTPUT: number of occurence
(define count-occ-p
  (lambda (v p)

      (reduce + (map (count-occ v) p) 0)
    ))
;;counts all letters' occurence in parapgraph
;;INPUT: value "v", paragraph "p"
;;OUTPUT: list of occurences. first element points 'a and last points 'z 
(define count-occ-p-all
  (lambda (v p)

    (if (eq? v 23)
      '()
      (cons (count-occ-p v p) (count-occ-p-all (+ v 1) p)))

    ))
;;decodes paragraph
;;INPUT: paragraph "p", procedure comes from Gen-Decoder-A,B "decoder"
;;OUTPUT: decedod paragraph
(define Code-Breaker-p 
  (lambda (p decoder)
    (if (null? p)
      '()
      (cons (decoder (car p)) (Code-Breaker-p (cdr p) decoder)))
    ))

;; -----------------------------------------------------
;; SPELL CHECKER FUNCTION

;;check a word's spell correctness
;;INPUT:a word(a global variable "dictionary" is included in the file "test-dictionary.ss", and can be used directly here)
;;OUTPUT:true(#t) or false(#f)
(define spell-checker 
  (lambda (w)
   ;;'SOME_CODE_GOES_HERE ;; *** FUNCTION BODY IS MISSING *** 
    (let loop ((w w)(d dictionary))
      (if (or (null? w) (null? d))
        #f
        (if (equal? w (car d))
          #t
          (loop w (cdr d))
        ))
   )))

;; -----------------------------------------------------
;; ENCODING FUNCTIONS

;;generate an Caesar Cipher single word encoders
;;INPUT:a number "n"
;;OUTPUT:a function, whose input=a word, output=encoded word
(define encode-n
  (lambda (n);;"n" is the distance, eg. n=3: a->d,b->e,...z->c
    (lambda (w);;"w" is the word to be encoded
     
     (if (null? w )
      '()
      (cons   (vtc (modulo (+ (ctv (car w)) n) 23) ) ((encode-n n) (cdr w)))
      )
     )))

;;encode a document
;;INPUT: a document "d" and a "encoder"
;;OUTPUT: an encoded document using a provided encoder
(define encode-d;;this encoder is supposed to be the output of "encode-n"
  (lambda (d encoder)
    ;;'SOME_CODE_GOES_HERE ;; *** FUNCTION BODY IS MISSING ***
      (if (null? d)
        '()
        (cons (encode-p (car d) encoder) (encode-d (cdr d) encoder))
        )
    ))
    
;; -----------------------------------------------------
;; DECODE FUNCTION GENERATORS
;; 2 generators should be implemented, and each of them returns a decoder

;;generate a decoder using brute-force-version spell-checker
;;INPUT:an encoded paragraph "p"
;;OUTPUT:a decoder, whose input=a word, output=decoded word
(define Gen-Decoder-A
  (lambda (p)
    (lambda (w)
        (define red-l (give-reduced-l p))
        (define maxV (apply max red-l))
        (define shift (+ (index maxV red-l) 1))
        ((encode-n  shift) w)
      )

    ))

;;generate a decoder using frequency analysis
;;INPUT:same as above
;;OUTPUT:same as above
(define Gen-Decoder-B
  (lambda (p)
    ;;'SOME_CODE_GOES_HERE ;; *** FUNCTION BODY IS MISSING ***
    (lambda (w)
      (define occ-l (count-occ-p-all 0 p))
      (define most-occ(apply max occ-l))
      (define most-occ-index (index most-occ occ-l))
      (define shift (modulo (- (ctv 'e) most-occ-index) 23))
      ((encode-n  shift) w)

      )

       
    ))

;; -----------------------------------------------------
;; CODE-BREAKER FUNCTION

;;a codebreaker
;;INPUT: an encoded document(of course by a Caesar's Cipher), a decoder(generated by functions above)
;;OUTPUT: a decoded document
(define Code-Breaker
  (lambda (d decoder)
    
      (if (null? d)
      '()
      (cons (Code-Breaker-p (car d) decoder) (Code-Breaker (cdr d) decoder)))

     ))

;; -----------------------------------------------------
;; EXAMPLE APPLICATIONS OF FUNCTIONS
;;(spell-checker '(h e l l o))
;;(define add5 (encode-n 5))
;;(encode-d document add5)
;;(define decoderSP1 (Gen-Decoder-A paragraph))
;;(define decoderFA1 (Gen-Decoder-B paragraph))
;;(Code-Breaker document decoderSP1)
