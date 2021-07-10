
class Solution{
public:
    int calculate(string exp){
        stack<int> numbers;
        stack<char> operands;
        exp+=" ";
        for(int i=0;i<exp.length();i++){
            if(exp[i]==' '){
                continue;
            }
            if(exp[i]=='-' or exp[i]=='+' or exp[i]=='/' or exp[i]=='*'){
                operands.push(exp[i]);
                continue;
            }
            string temp="";
            while(i<exp.length() and exp[i]>='0' and exp[i]<='9'){
                temp+=exp[i++];
            }
            i--;
            stringstream str(temp);
            int num;
            str>>num;
            numbers.push(num);
            if(!operands.empty()){
                if(operands.top()=='*' or operands.top()=='/'){
                    int n1=numbers.top();
                    numbers.pop();
                    int n2=numbers.top();
                    numbers.pop();
                    if(operands.top()=='*'){
                        numbers.push(n1*n2);
                        operands.pop();
                    }else if(operands.top()=='/'){
                        numbers.push(n2/n1);
                        operands.pop();
                    }
                }
            }
        }
        stack<char> ops;
        stack<int> nums;
        while(!operands.empty()){
            ops.push(operands.top());
            operands.pop();
        }
        while(!numbers.empty()){
            nums.push(numbers.top());
            numbers.pop();
        }
        while(!ops.empty()){
                int n1=nums.top();
                nums.pop();
                int n2=nums.top();
                nums.pop();
                if(ops.top()=='+'){
                    nums.push(n1+n2);
                }else if(ops.top()=='-'){
                    nums.push(n1-n2);
                }
            ops.pop();
        }

        return nums.top();
    }
};