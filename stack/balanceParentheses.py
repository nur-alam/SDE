# def isValidParentheses(expr):
#     stack = []
#     for char in expr:
#         if char in ['(', '{', '[']:
#             stack.append(char)
#         else:
#             if not stack:
#                 return False
#             current_char = stack.pop()
#             if current_char == '(':
#                 if char != ')':
#                     return False
#             if current_char == '{':
#                 if char != '}':
#                     return False
#             if current_char == '[':
#                 if char != ']':
#                     return False
#     if stack:
#         return False
#     else:
#         return True

# def isValid(s: str) -> bool:
#     stack = []
#     closeToOpen = {')': '(', '}': '{', ']': '['}
#     for char in s:
#         if char in closeToOpen:
#             if stack and stack[-1] == closeToOpen[char]:
#                 stack.pop()
#             else:
#                 return False
#         else:
#             stack.append(char)


def isValid(s: str) -> bool:
    stack = []
    closeToOpen = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in closeToOpen:
            if stack and char == stack[-1]:
                # if stack and stack[-1] == closeToOpen[char]:
                stack.pop()
            else:
                return False
        else:
            stack.append(char)
    return True if not stack else False


if __name__ == '__main__':
    # expr = "{()}[]"
    # expr = '({[]})'
    # expr = '[()]{}{[()()]()}'
    expr = '[](){}]'
    if isValid(expr):
        print('Balanced')
    else:
        print('Not Balanced')
    # closeToOpen = {')': '(', '}': '{', ']': '['}
    # print(')' in closeToOpen)
    # print(closeToOpen.get(')'))
    # print(closeToOpen.get('d') == None)
