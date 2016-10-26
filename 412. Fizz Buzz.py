"""
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
"""

class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        '''
        # norm
        if not n or n==0:
            return []
        res=[]
        for eachnum in range(1,n+1):
            if not eachnum%3 and not eachnum%5:
                res.append("FizzBuzz")
            elif not eachnum%3:
                res.append("Fizz")
            elif not eachnum%5:
                res.append("Buzz")
            else:
                res.append(str(eachnum))
        return res
        '''        
        # reconstruct
        return [str(each) if (each%3!=0 and each%5!=0) else ("Fizz"*(each%3==0)+"Buzz"*(each%5==0)) for each in range(1,n+1)]
