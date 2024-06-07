### Probelm Link
[Replace Words](https://leetcode.com/problems/replace-words/description/)

### Solution:
Sentence words need to check is it exists in the dictionary or not. 
Each word need to check it it exist in the `dictionary` or not if it's add the current word. otherwise add full word

### Code 

```python 
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        checker = set(dictionary)
        word_list = sentence.split()

        ans = []
        for word in word_list:
          current = ''
          fg = False
          for ch in word:
            current += ch
            if current in checker:
              ans.append(current)
              fg = True
              break
          if fg==False:
             ans.append(word)
        return ' '.join(ans)  

```