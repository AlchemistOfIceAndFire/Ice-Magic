//
// Created by huanyan on 2021/11/19.
//

/*
 * case1: in the last line, words need have a left justifying, and fill the bland in the end of words, just set one blank between words.
 * case2: int the non-last line and just have one word, same to the case1
 * case3: int the non-last line,
 *
 */

class Solution {
public:
    string blank(int n) {
        return string(n, ' ');
    }

    string join(vector <string> &words, int left, int right, string blanks) {
        string s = words[left];
        for (int i = left + 1; i < right; i++) {
            s += blanks + words[i];
        }
        return s;
    }

    vector <string> fullJustify(vector <string> &words, int maxWidth) {
        vector <string> answer;
        int right = 0, n = words.size();
        while (true) {
            int left = right, sumLen = 0;
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth) {
                // now, the sumLen just have the max words length, maxWidth - sumLen is the number of blank
                sumLen += words[right++].length();
            }

            // in the last line
            if (right == n) {
                string s = join(words, left, right, " ");
                answer.push_back(s + blank(maxWidth - s.size()));
                break;
            }

            int wordsNum = right - left, blanksNum = maxWidth - sumLen;

            // in the non-last line and just have one word in this line
            if (wordsNum == 1) {
                answer.push_back(words[left] + blank(blanksNum));
                continue;
            }

            // in the non-last line, and have at least two words
            // minimum blanks number between words
            int avgBlanksNum = blanksNum / (wordsNum - 1);
            // the count of space which need added blank
            int extraSpacesNum = blanksNum % (wordsNum - 1);

            // add extra blanks
            string s1 = join(words, left, left + extraSpacesNum + 1, blank(avgBlanksNum + 1));
            // add average blanks
            string s2 = join(words, left + extraSpacesNum + 1, right, blank(avgBlanksNum));
            // add blanks between s1 and s2
            answer.push_back(s1 + blank(avgBlanksNum) + s2);
        }
        return answer;
    }
};