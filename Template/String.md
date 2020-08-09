## 字符串常用操作

1. 字符串相加

   ```c++
   string s1, s2;
   string s = s1 + s2;
   ```

2. 字符删除

   ```c++
   s.erase(s.begin() + i);
   ```

3. 字符串删除尾部字符

   ```c++
   s.pop_back();
   ```

4. 字符串翻转

   ```c++
   reverse(s.begin(), s.end());
   ```

5. 字符串里面去空格

   ```c++
   stringstream ss(s);
   vector<string> v;
   string word;
   while (ss>>word) {
       v.push_back(word);
   }
   ```

6. 字符串转数字

   ```c++
   atoi(s.c_str());
   ```

7. 数字转字符串

   ```c++
   to_string(a);
   ```

   