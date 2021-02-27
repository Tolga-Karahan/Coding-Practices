#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

void extract_tags_and_value(vector<string>&, string&, string&, string&);
bool compare_stack(vector<string>&, stack<string>&);
string find_attribute(vector<string>&, vector<string>&, string&, string&);
void showstack(stack<string>);
void print_vector(vector<string>&);

void extract_tags_and_value(vector<string>& query_tags, string& line,
                            string& last_tag, string& attr){
    string token;
    stringstream ss(line);

    while (getline(ss, token, '.')) {
        query_tags.push_back(token);
    }
    string last_token = query_tags.back();
    query_tags.pop_back();

    size_t pos = 0;
    pos = last_token.find('~');
    last_tag = last_token.substr(0, pos);
    query_tags.push_back(last_tag);
    last_token.erase(0, pos + 1);
    attr=last_token;
}

bool compare_stack(vector<string>& query_tags, stack<string>& tags_stack){
  if(query_tags.size() != tags_stack.size()){
    return false;
  }else if(query_tags.size() == 0 || tags_stack.size() == 0){
    return false;
  }

  for(int i = query_tags.size() - 1; i >= 0; i--){
    if (tags_stack.top().find(query_tags.at(i)) == string::npos){
      return false;
    }
    tags_stack.pop();
  }
  return true;
}

string find_attribute(vector<string>& query_tags, vector<string>& tokens,
                      string& last_tag, string& attr){
    int index = -1;
    bool in_tag_flag = false;
    stack<string> tags;

    for(int i = 0; i < tokens.size(); i++){
        if(tokens.at(i).find("<") != string::npos &&
           tokens.at(i).find("</") == string::npos){
            if (tokens.at(i).find("<" + last_tag) != string::npos){
                in_tag_flag = true;
            }else{
              in_tag_flag = false;
            }
            tags.push(tokens.at(i));
        }else if(tokens.at(i).find("</") != string::npos){
            if (tags.size() != 0)
              tags.pop();
        }else if(in_tag_flag){
            if(tokens.at(i).size() == attr.size() &&
               tokens.at(i).find(attr) != string::npos &&
               compare_stack(query_tags, tags) &&
               i < (tokens.size() - 2)){
               index = i+2;
               break;
            }
        }
    }
    if (index != -1){
        string result = tokens.at(index);
        size_t pos = 0;
        pos = result.find('>');
        if(pos)
          return result.substr(0, pos);
        else
          return result;
    }
    else{
        return "Not Found!";
    }
}

void print_vector(vector<string> &v){
    for(int i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;
}

void showstack(stack <string> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << "\n";
}

int main() {
    int n, q;
    string line;
    vector<string> tokens;
    vector<string> queries;
    string inputs = "";
    
    cin >> n >> q;

    while(n >= 0){
        string token;
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        stringstream ss(line);

        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        n--;
    }

    while(q > 0){
        getline(cin, line);
        queries.push_back(line);
        q--;
    }
    for(int i = 0; i < queries.size(); i++){
        vector<string> query_tags;
        string last_tag;
        string attr;
        string result = "Not Found!";
        cout << queries.at(i) << endl;
        extract_tags_and_value(query_tags, queries.at(i), last_tag, attr);
        result = find_attribute(query_tags, tokens, last_tag, attr);
        cout << result << endl;
    }
    return 0;
}