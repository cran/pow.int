\name{pow.int}
\alias{pow.int}
\alias{\%^\%}
\title{
	Binary Exponentiation
}
\description{
	Fast exponentiation when the exponent is an integer.
}
\usage{
pow.int(x, n)
x \%^\% n
}
\arguments{
  \item{x}{a numeric vector giving the base.}
  \item{n}{an integer vector giving the exponent.}
}
\value{A numeric vector.}
\author{Jonathan Debove}
\note{
	This function is just a wrapper around \code{R_pow_di} in the Rmath
	library.
}
\examples{
3 \%^\% 12L
}
