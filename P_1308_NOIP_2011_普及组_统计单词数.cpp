#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string word, text;
    // 1. 读取输入
    getline(cin, word);
    getline(cin, text);

    // 2. 转小写（不区分大小写）
    for (int i = 0; i < word.length(); i++) word[i] = tolower(word[i]);
    for (int i = 0; i < text.length(); i++) text[i] = tolower(text[i]);

    // 3. 关键：前后加空格，变成“ 单词 ”，确保全词匹配
    word = " " + word + " ";
    text = " " + text + " ";

    int cnt = 0;
    int first_pos = -1;
    size_t pos = text.find(word); // 查找第一次出现的位置

    if (pos == string::npos) {
        cout << -1 << endl;
    } else {
        first_pos = pos;
        while (pos != string::npos) {
            cnt++;
            pos = text.find(word, pos + 1); // 从上一个位置后面继续找
        }
        cout << cnt << " " << first_pos << endl;
    }

    return 0;
}