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

(define (square x) (* x x))

(define (abs x)
  (cond ((< x 0) (- x))
	(else x)))

(define (average x y)
  (/ (+ x y) 2))

(define (expt b n)
  (define (iter b n rec)
    (cond ((< n 1) rec)
	  ((even? n) (iter (square b) 
			   (/ n 2) rec))
	  (else (iter b 
		      (- n 1) 
		      (* rec b)))))
  (iter b n 1))

(define (gcd a b)
  (define (iter a b)
    (if(= b 0)
       a
       (iter b 
	     (remainder a b))))
  (if(> a b)
     (iter  a b)
     (iter b a)))

(define (sqrt x accuracy)
  (define (improve guess)
    (average guess (/ x guess)))
  (define (good-enough? guess)
    (< (abs (- (square guess) x)) 
       accuracy))
  (define (sqrt-iter guess)
    (if(good-enough? guess)
       guess
       (sqrt-iter (improve guess))))
  (sqrt-iter 1.0))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (define (next i)
    (cond ((= i 2) 3)
	  (else (+ i 2))))
  (cond ((> (square test-divisor) n) n)
	((divides? test-divisor n) test-divisor)
	(else (find-divisor) n (next test-divisor))))
			  
(define (accumulate-sum term a next b)
  (define (as-iter a sum)
    (if (> a b)
	sum
	(as-iter (next a) (+ sum (term a)))))
  (as-iter a 0))

(define (accumulate-sum-count term calc-x count); f_1 + ... + f_count
  (define (asc-iter count sum)
    (if (> count 0)
	(asc-iter (- count 1) (+ sum (term (calc-x count))))
	sum))
  (asc-iter count 0))

(define (accumulate-product term a next b)
  (define (ap-iter a product)
    (if (> a b)
	product
	(ap-iter (next a) (* product (term a)))))
  (ap-iter a 1))

(define (accumulate-product-count term calc-x count); f_1 * ... * f_count
  (define (apc-iter count product)
    (if (> count 0)
	(apc-iter (- count 1) (* product (term (calc-x count))))
	product))
  (apc-iter count 1))

(define (integral-rectangle func a b steps)
  (define (next x)
    (+ x (/ (- b a) steps)))
  (define (term x)
    (* (func x) (/ (- b a) steps)))
  (accumulate-sum term a next b))

(define (factorial n)
  (accumulate-product-count (lambda (x) x) (lambda (n) (+ n 1)) (- n 1)))

(define (integral-simpson func a b n);only applies to functions with 4 level derivative.
  (define (calcxn i) (/ (+ (* a (- n i)) (* b i)) n))
  (define (calcxn-half j) (/ (+ (* b (- (* 2 j) 1)) (* a (- (+ (* 2 n) 1) (* 2 j)))) 2 n))
  (/ (* (- b a) (+ (func a) (func b)
		   (* 2 (accumulate-sum-count func calcxn (- n 1)))
		   (* 4 (accumulate-sum-count func calcxn-half n))))
     6 n))

(define 
