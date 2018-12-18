(define (even? x)
  (= (remainder x 2)
     0))

(define (odd? x)
  (= (remainder x 2)
     1))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (positve? x)
  (cond ((> x 0) #t)
	(else #f)))
					;above are functions that judge.

(define (square x) (* x x))

(define (abs x)
  (cond ((< x 0) (- x))
	(else x)))

(define (average x y)
  (/ (+ x y) 2))

(define (transformation-family-t mode p q a b n)
  (define param (cons p q))
  (define value (cons a b))
  (define (calc cparam cvalue)
    (cons (+ (* (cdr cparam)
		(cdr cvalue))
	     (* (car cvalue) 
		(+ (car cparam) 
		   (cdr cparam))))
	  (+ (* (car cvalue)
		(cdr cparam)) 
	     (* (cdr cvalue) 
		(car cparam))))) 
  (define (iter iparam ivalue in)
    (cond ((> 1 in) ivalue) 
	  (else (iter iparam 
		      (calc iparam 
			    ivalue) 
		      (- in 1)))))
  (define (new-param nparam)
    (let ((x (square (car nparam))) 
	  (y (* 2 
		(* (car nparam) 
		   (cdr nparam)))) 
	  (z (square (cdr nparam)))) 
      (cons (+ x z) 
	    (+ y z))))
  (define (fast-iter fparam fvalue fn)
    (cond ((> 1 fn) fvalue) 
	   
	  ((odd? fn) (fast-iter fparam 
			   (calc fparam fvalue) 
			   (- fn 1)))
	  (else (fast-iter (new-param fparam) 
				 fvalue 
				 (/ fn 2)))))
  (cond ((= mode 1) (iter param 
			  value 
			  n))
	((= mode 2) (fast-iter param 
			       value 
			       n))))

(define (expt b n)
  (define (iter b n rec)
    (cond ((< n 1) rec)
	  ((even? n) (iter (square b) 
			   (/ n 2) rec))
	  (else (iter b 
		      (- n 1) 
		      (* rec b)))))
  (iter b n 1))

(define (factorial n)
  (define (iter product counter)
    (if (> counter n)
	product
	(iter (* product counter)
	      (+ counter 1))))
  (iter 1 1))

(define (fibonacci mode n);mode: 1 normal, 2 fast
  (cdr (transformation-family-t mode 0 1 1 0 n)))

(define (gcd a b)
  (define (iter a b)
    (if (= b 0)
	a
	(iter b 
	      (remainder a b))))
  (if (> a b)
      (iter  a b)
      (iter b a)))
					;tested, involved in other forms.

(define (sqrt x accuracy)
  (define (improve guess)
    (average guess (/ x guess)))
  (define (good-enough? guess)
    (< (abs (- (square guess) x)) 
       accuracy))
  (define (sqrt-iter guess)
    (if (good-enough? guess)
	guess
	(sqrt-iter (improve guess))))
  (sqrt-iter 1.0))






					;tested, functioning, not involved in other forms.


(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (define (next i)
    (cond ((= i 2) 3)
	  (else (+ i 2))))
  (cond ((> (square test-divisor) n) n)
	((divides? test-divisor n) test-divisor)
	(else (find-divisor) n (next test-divisor))))

;(define (search f neg-point pos-point)
;(let ((mid-point (average neg-point
;			    pos-point)))
;    (if (close-enough? neg-point pos-point)
;	mid-point
;	(let ((test-value (f midpoint)))
;	  (cond ((positive? )()
			  
(define (accumulate-sum term a next b)
  (if (> a b)
      0
      (+ (term a)
	 (accumulate-sum term (next a) next b))))

(define (accumulate-sum-count term a b calc-x count); f_1 + ... + f_count
  (if (> count 0)
      (+ (term (calc-x count))
	 (accumulate-sum-count term a b calc-x (- count 1)))
      0))

;(define (pi-term a
;  (/ 1.0 (* a (+ a 2))));for test reason
;(define (pi-next a)
;  (+ a 4));for test reason

(define (integral-rectangle func a b steps)
  (define (next x)
    (+ x (/ (- b a) steps)))
  (define (term x)
    (* (func x) (/ (- b a) steps)))
  (accumulate-sum term a next b))
			;havn't been tested yet.


(define (integral-simpson func a b n);only applies to functions with 4 level derivative.
  (define (calcxn i) (/ (+ (* a (- n i)) (* b i)) n))
  (define (calcxn-half j) (/ (+ (* b (- (* 2 j) 1)) (* a (- (+ (* 2 n) 1) (* 2 j)))) 2 n))
  (/ (* (- b a) (+ (func a) (func b)
		   (* 2 (accumulate-sum-count func a b calcxn (- n 1)))
		   (* 4 (accumulate-sum-count func a b calcxn-half n))))
     6 n))
