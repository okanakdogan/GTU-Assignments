;;
;; A lexer for subset of the scheme language.
;;
;; For more details see the homework description.
;;

;; OKAN AKDOGAN - 121044017
;; -------------------------------------------
;; Helper functions ...

;; takes numeric to and returns symbol for token
;; INPUT: num- code for find token symbol
;; OUTPUT: token symbol 
(define tokenCode 
	(lambda (num)
		(cond ((eq? num 1) 'INT_LITERAL)
			((eq? num 2) 'BOOL_LITERAL)
			((eq? num 3) 'STRING_LITERAL)
			((eq? num 4) 'QUOTE)
			((eq? num 5) 'LAMBDA)
			((eq? num 6) 'IF)
			((eq? num 7) 'LET)
			((eq? num 8) 'DEFINE)
			((eq? num 9) 'AND)
			((eq? num 10) 'OR)
			((eq? num 11) 'NOT)
			((eq? num 12) 'IDENTIFIER)
			((eq? num 13) 'LPARAN)
			((eq? num 14) 'RPARAN)
			(else 'unknown))
		))
;;takes string and check is it a keyword in Scheme pl.
;;INPUT k -string for check
;;OUTPUT: token numeric code

(define keywordCode
	(lambda (k)
		(cond ((string=? k "quote") 4)
			((string=? k "lambda") 5)
			((string=? k "if") 6)
			((string=? k "let") 7)
			((string=? k "define") 8)
			((string=? k "and") 9)
			((string=? k "or") 10)
			((string=? k "not") 11)
			(else 12)
			)
		))
;; takes a char and returns a code for "alphabetic, numeric, alphanumeric or # char"
;; INPUT: c- character
;; OUTPUT: num code for result 
(define charClass
	(lambda (c)
		(cond ((or (char-alphabetic? c) (isIdenChar c)) 0)
			((char-numeric? c) 1)
			((char-alphanumeric? c)3)
			((eq? c #\#) 4)
			(else 99))
		))
;;check character is a identifier symbol
;;INPUT: c- char
;;OUTPUT: if it is identifier boolean true o\w false
(define isIdenChar 
	(lambda (c)
		(cond ((eq? c #\!) #t)
			((eq? c #\$) #t)
			((eq? c #\%) #t)
			((eq? c #\&) #t)
			((eq? c #\*) #t)
			((eq? c #\+) #t)
			((eq? c #\-) #t)
			((eq? c #\.) #t)
			((eq? c #\/) #t)
			((eq? c #\:) #t)
			((eq? c #\<) #t)
			((eq? c #\=) #t)
			((eq? c #\>) #t)
			((eq? c #\?) #t)
			((eq? c #\@) #t)
			((eq? c #\^) #t)
			((eq? c #\_) #t)
			((eq? c #\~) #t)
			(else #f))
		))
;; appends strings in a list
;; INPUT: s- list of strings ( string string ....)
;; OUTPUT: a string contains all of strings in input list
(define lexeme-appender 
	(lambda(s)
		(if (null? s)
			""
			(string-append (car s)(lexeme-appender (cdr s)))
			)
		))
;; changes a result of lexemeFunction. ("a" "b" "c" 0 "...") to ("abc" 0 "...")
;; INPUT: s- list of (strings ...  num string)
;;		lexemeFunc: function would create a list of (strings ... tokenCode restOfString)
;; OUTPUT: list a generally (string num string) 

(define lexemeResulter 
	(lambda(s lexemeFunc)
		(define l (lexemeFunc s))
		(cons (lexeme-appender (list-head l (- (length l) 2))) (list-tail l (- (length l) 2)))		
	))
;; takes a string and tokenize first identifier. returns a list that contains token parts, tokencode and rest of string
;; INPUT: s string for tokenize
;; OUTPUT: list of (strings ... tokenCode restOfString)
(define lexemeIdentifier
	(lambda (s)
		(if (and (not (string-null? s)) (or (char-alphanumeric? (string-ref s 0)) (isIdenChar (string-ref s 0)))) 
			(cons (string (string-ref s 0)) (lexemeIdentifier (substring s 1 (string-length s))) )
			(cons 12 (list s))
		  )
	) )
;; takes a string and tokenize first integer_literal. returns a list that contains token parts, tokencode and rest of string
;; INPUT: s string for tokenize
;; OUTPUT: list of (strings ... tokenCode restOfString)

(define lexemeInt
	(lambda (s)
		(if (and (not (string-null? s)) (char-numeric? (string-ref s 0)) ) 
			(cons (string (string-ref s 0)) (lexemeInt (substring s 1 (string-length s))) )
			(cons 1 (list s))
		  )
	) )
;; takes a string and tokenize first string_literal. returns a list that contains token parts, tokencode and rest of string
;; INPUT: s string for tokenize
;; OUTPUT: list of (strings ... tokenCode restOfString)
(define lexemeString
	(lambda (s)
		(if (and (not (string-null? s)) (not (eq? (string-ref s 0)  #\"))) 
			(cons (string (string-ref s 0)) (lexemeString (substring s 1 (string-length s))) )
			(cons "\"" (cons 3 (list (substring s 1 (string-length s)))))
		  )
	) )

		
;; -------------------------------------------
;; LEXER
;; 
;; Reads a program from the string argument and returns the token type and the corresponding lexeme...

(define lexer 
  (lambda (p)
  	(define newS (string-trim p)) ;; delete spaces both end of string
	(define result (if (string-null? newS)
		'()
		(cond ((eq? (string-ref newS 0) #\#) ;; check for first char is # ( strat of boolean literal)
						(if (or (eq? (string-ref newS 1) #\t) (eq? (string-ref newS 1) #\f));; check for false or true and tokenize
							(append (list (substring newS 0 2) 2 ) (list (substring newS 2 (string-length newS)))) 
							(append (list (substring newS 0 2) 99) (list (substring newS 2 (string-length newS))))))

				;;check first char is "(" left paranthesis and tokenize
				((eq? (string-ref newS 0) (string-ref "(" 0)) 
						(append (list (substring newS 0 1) 13) (list (substring newS 1 (string-length newS)))))
				;;check first char is ")" right paranthesis and tokenize
				((eq? (string-ref newS 0) (string-ref ")" 0)) 
						(append (list (substring newS 0 1) 14) (list (substring newS 1 (string-length newS)))))
				;;check first char is it alphabetic to tokenize in identifier			
				((eq? (charClass (string-ref newS 0)) 0) (lexemeResulter newS lexemeIdentifier))
				;;check first char is it double quote if so tokenize in String lexer
				((eq? (string-ref newS 0) #\") (lexemeResulter (substring newS 1 (string-length newS)) lexemeString))
				;;check first char is it numeric char if so tokenize in Integer lexer
				((eq? (charClass (string-ref newS 0)) 1) (lexemeResulter newS lexemeInt))
				(else '())
			)
		))
		;;add first double quote if it is a string literal
		(define newResult (if (eq? (string-ref newS 0) #\")
				(cons (string-append "\"" (car result)) (cdr result))
				result
			))

		;;Check is Identifier a keyword
		(define code (if (eq? (car (cdr newResult)) 12)
			(keywordCode (car newResult))
			(car (cdr newResult))
			))
		;; change order of last result to tokenName token make list with rest of result (there is a recursive result)
		(define lex (if (not (null? newResult))
		(cons (cons (tokenCode code) (list (car newResult))) (if (string-null? (third newResult)) '() (lexer (third newResult))))
				newResult)
		)
		lex		
  )
)

