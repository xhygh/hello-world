/*


*/



/************
给出俩word，一个dict，从startword转化到endword需要经过几个单词，算上这俩word。
1.每次只能改变一个字母～
2.变换过程中的中间单词必须在字典中出现～（第一个beginWord不需要出现，最后一个endWord需要在字典中出现～）
solution：
当前节点是startword，找他的邻点，与他有一个字母不同的都是他的邻点，再找他邻点的邻点，直到找到endword。典型的BFS算法
dist记录长度，每个当前节点的邻点都存入queue，

超时
*************/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> tovisit;//当前节点的邻点，邻点与当前节点相差一个letter
        addToVisitWord(beginWord,wordList,tovisit);//找到当前节点的所有邻点
        int dist = 2; // startword 和endword
        while(!tovisit.empty()){
            int n = tovisit.size();//当前‘层’的邻点
            for(int i=0;i<n;i++){
                cout<<tovisit.front()<<endl;
                string firstword = tovisit.front();//获取第一个word
                tovisit.pop();//删除已获取的word
                if(firstword==endWord) return dist;//如果能够转化，在此处return dist
                addToVisitWord(firstword,wordList,tovisit);//添加当前节点的邻点
            }
            dist++;//本‘层’的邻点都处理过了，距离+1
        }
        return 0;//没有转化序列
    }
private:
    void addToVisitWord(string firstword,vector<string>& wordList,queue<string>& tovisit){
        //本函数处理当前firstword节点，删除wordlist中所有firstword的邻点，即与其word相差一个字母的word
        //并将这些邻点words加入tovisit，作为下一个firstword
        wordList.erase(remove(wordList.begin(),wordList.end(),firstword),wordList.end());//删除wordlist中的当前节点word,不能再加入queue
        for(int idx=0;idx<firstword.size();idx++){//当前节点的每个字母变化的变形都从wordlist中删除，并加入tovisit
            char tmp_letter = firstword[idx];//当前字母留底
            for(int i=0;i<26;i++){//检查26个字母变型
                firstword[idx] = 'a'+i;
                if(find(wordList.begin(),wordList.end(),firstword)!=wordList.end()){
                    //如果wordlist中有该变形
                    wordList.erase(remove(wordList.begin(),wordList.end(),firstword),wordList.end());//删除变形
                    tovisit.push(firstword);//保留当前节点的邻点
                }
            }
            firstword[idx]=tmp_letter;
        }
    }
};

/*********
修改成unordered_set<string>格式就通过了，看来是删除操作好事太长
39 / 39 test cases passed.
	Status: Accepted
Runtime: 103 ms
71.29%
O(n),O(n)
*********/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);
        queue<string> tovisit;//当前节点的邻点，邻点与当前节点相差一个letter
        addToVisitWord(beginWord,dict,tovisit);//找到当前节点的所有邻点
        int dist = 2; // startword 和endword
        while(!tovisit.empty()){
            int n = tovisit.size();//当前‘层’的邻点
            for(int i=0;i<n;i++){
                string firstword = tovisit.front();//获取第一个word
                tovisit.pop();//删除已获取的word
                if(firstword==endWord) return dist;//如果能够转化，在此处return dist
                addToVisitWord(firstword,dict,tovisit);//添加当前节点的邻点
            }
            dist++;//本‘层’的邻点都处理过了，距离+1
        }
        return 0;//没有转化序列
    }
private:
    void addToVisitWord(string firstword,unordered_set<string>& wordList,queue<string>& tovisit){
        //本函数处理当前firstword节点，删除wordlist中所有firstword的邻点，即与其word相差一个字母的word
        //并将这些邻点words加入tovisit，作为下一个firstword
        wordList.erase(firstword);//删除wordlist中的当前节点word,不能再加入queue
        for(int idx=0;idx<firstword.size();idx++){//当前节点的每个字母变化的变形都从wordlist中删除，并加入tovisit
            char tmp_letter = firstword[idx];//当前字母留底
            for(int i=0;i<26;i++){//检查26个字母变型
                firstword[idx] = 'a'+i;
                if(wordList.find(firstword)!=wordList.end()){
                    //如果wordlist中有该变形
                    wordList.erase(firstword);//删除变形
                    tovisit.push(firstword);//保留当前节点的邻点
                }
            }
            firstword[idx]=tmp_letter;
        }
    }
};





/************
two-end搜索
使用2个指针phead和ptail节省时间，在每轮BFS，依靠head和tail的相对size使用phead得到小集合，降低时间.
使用图的方法，将开头和结尾分两个set，本题不用管从startword到endword的路径是什么，所以用set可节省时间。
遍历head set中的word，对于其的每个变形，考察是否在tail set中，如果是，证明可变化，return dist。否则，构造新head set，dist++。
39 / 39 test cases passed.
	Status: Accepted
Runtime: 33 ms
95.15%
***********/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict,head,tail,*phead,*ptail;//集合好用
        for(int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);
        if (dict.find(endWord)==dict.end()) return 0;//如果endWord不再dict中，不可转化
        head.insert(beginWord);
        tail.insert(endWord);
        int dist=2;
        while(!head.empty()&&!tail.empty()){
            if (head.size()<tail.size()){
                phead=&head;
                ptail=&tail;
            }else{
                phead=&tail;
                ptail=&head;
            }
            
            unordered_set<string> tmp;
            for(auto head_itr=phead->begin();head_itr!=phead->end();head_itr++){
                //对于headset中的每个word考察其变形
                string word = *head_itr;
                dict.erase(word);//字典中删除，防止重复考察
                for(int idx=0;idx<word.size();idx++){
                    char tmpletter = word[idx];//留底
                    for(int i=0;i<26;i++){
                        word[idx] = 'a' + i;//一个字母变形
                        //对于一个字母不同的所有变形
                        if (ptail->find(word)!=ptail->end()) return dist;//如果下一个变形在tailset内，证明走通，返回dist
                        if(dict.find(word)!=dict.end()){
                            //如果字典中有下一个变形
                            tmp.insert(word);//保存变形，作为下一个head或者tailset的元素
                            dict.erase(word);//从字典中删除已进入set的元素
                        }
                    }
                    word[idx] = tmpletter;
                }
                
            }
            dist++;
            swap(*phead,tmp);
        }
        return 0;
    }
};
