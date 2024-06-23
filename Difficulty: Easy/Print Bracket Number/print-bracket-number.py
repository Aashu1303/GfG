#User function Template for python3
class Solution:
    def bracketNumbers(self, str):
        # code here
        result = []
        stack = []
        count = 1
        
        for char in str:
            if char == '(':
                stack.append(count)
                result.append(count)
                count += 1
            elif char == ')':
                result.append(stack.pop())
        
        return result 

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.bracketNumbers(S)
        for value in answer:
            print(value, end=" ")
        print()

# } Driver Code Ends