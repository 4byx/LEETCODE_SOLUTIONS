class Solution {
public:
    bool parseBoolExpr(string ex) {
        stack<char> up;
        stack<char> exp;
        for(auto x : ex){
            if(x=='&' or x=='!' or x=='|'){
                up.push(x);
            }else if(x==')'){
                bool ans = (exp.top()=='f')?false:true;
                while(exp.top()!='('){
                        if(up.top() == '&'){
                            ans &= (exp.top() == 'f')?false:true;
                        }else if(up.top() == '!'){
                            ans = !((exp.top() == 'f')?false:true);
                        }else{
                            ans |= (exp.top() == 'f')?false:true;
                        }
                    exp.pop();
                }
                up.pop();
                exp.pop();
                exp.push((ans==true)?'t':'f');
            }else if(x!=','){
                exp.push(x);
            }
        }
        return exp.top() == 'f'?false:true;
    }
};