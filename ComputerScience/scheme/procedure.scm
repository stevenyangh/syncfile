(define (make-accumulator init bin-op)
  (lambda (add)
    (set! init (bin-op init add))
    init))

(define (make-monitored-1-para procedure)
  (define accumulate (make-accumulator 0 +))
  (define (dispatch m)
    (if (eq? m 'how-many-calls?)
	(accumulate 0)
	(begin (accumulate 1)
	       (procedure m)
	       )))
  dispatch)






