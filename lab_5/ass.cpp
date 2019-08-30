#include<bits/stdc++.h>
using namespace std;

int validity=1;

struct node
{
	string data;
	string key;
	node* next;
};

vector <struct node*> table;

int calKey(string variable){
	int val=0;
	for(int i=0;i<variable.length();i++){
		val+=variable[i]; 
	}
	return val%37;
}

void insert(string var,int val){
	int ikey = calKey(var);
	node* temp = new node();
	temp->key = var;
	temp->data = to_string(val);
	temp->next = NULL;
	if(table[ikey] == NULL){
		table[ikey] = temp;
	}
	else{
		node* temp2 = table[ikey];
		temp->next = temp2;
		table[ikey] = temp;
	}

}

node* search(string p){
	int ikey = calKey(p);
	node* temp = table[ikey];
	while(temp!=NULL){
		if(!p.compare(temp->key))
			break;
	}
	return temp;	
}

string integer(string p){
	node* ptr = search(p);
	return ptr->data;
}

struct et 
{ 
    string value; 
    et* left, *right; 
}; 

int prec(string c) 
{ 
	if(c=="@")
	return 4;
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
}  
vector<string> infixToPostfix(vector<string> s) 
{ 
    std::stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if(s[i]!="(" && s[i]!=")" && s[i]!="+" && s[i]!="*" && s[i]!="-" && s[i]!="/" && s[i]!= "@"&&s[i]!="^") {
        	if(s[i]!="")
        	ns.push_back(s[i]); 
    	}
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == "(") 
          
        st.push("("); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop();
                ns.push_back(c); 
            } 
            if(st.top() == "(") 
            { 
                st.pop();  
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.top() != "N" && ((prec(s[i]) <= prec(st.top()))&&(prec(s[i])!=3&&prec(st.top())!=3))) 
            { 
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != "N") 
    { 
                string c = st.top(); 
                st.pop();
                ns.push_back(c); 
    } 
      	
    return ns;
  
}  

bool isOperator(string c) 
{ 
    if (c.size()==1&&(c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^"|| c=="@")) 
        return true; 
    return false; 
} 

bool isOperator(char c) 
{ 
    if ((c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^')) 
        return true; 
    return false; 
} 

bool isunary(string p,int i){
	if(i==0||p[i+1]==41||isOperator(p[i-1])||p[i-1] == 61||p[i-1]==40)
		return true;	
	return false;
}

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  
// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2;
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else if(postfix[i] == "@"){
        	string a = "0";
        	t = newNode(postfix[i]);
        	t1 = st.top();
        	st.pop();
        	t->right = t1;
        	t2  = newNode(a);
        	t->left = t2;
        	st.push(t);
        }
        else // operator 
        { 
            t = newNode(postfix[i]); 
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
            //  make them children 
            t->right = t1; 
            t->left = t2; 
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
    return t; 
} 

int eval(et* a){
    if(a->left==NULL&&a->right==NULL){
    	try{
    		return stoi(a->value);
    	}
    	catch(...){
    		return stoi(integer(a->value));
    	}
    }
    int A = eval(a->left);
    int B = eval(a->right);
    if(a->value == "+")
        return A+B;
    else if(a->value == "-")
        return A-B;
    else if(a->value == "*")
        return A*B;
    else if(a->value == "%")
        return A%B;
    else if(a->value == "/")
        return A/B;
    else if(a->value == "^")
        return pow(A,B);
    else if(a->value == "@")
    	return -1*B;
}

vector <string> Thevals(string p){
    vector<string> P;
    string temp="";
	for(int i=0; i<p.length();i++)
	{
		if((p[i]>=48 && p[i]<=57)||(p[i]>=65&&p[i]<=90)||(p[i]>=97&&p[i]<=112))
		{
          temp+=p[i];
		}
		else
		{
            P.push_back(temp);
            temp="";
            if(p[i] == 45 && isunary(p,i))
            	p[i] = '@';

            temp+=p[i]; 
            P.push_back(temp);
            temp="";
		}   
	}
    P.push_back(temp);
    return P;
}

int numerical_exp(string p){
	vector<string> P;
	P = Thevals(p);
	for(int i=0;i<P.size();i++){
		if((P[i][0]>=65&&P[i][0]<=90)||(P[i][0]>=97&&P[i][0]<=1122)){
			node* temp = search(P[i]);
			if(temp == NULL)
			{
				validity = 0;
				break;
			}

	}
}
	if(validity == 0)
		return 0;
	else{
	vector<string> postexp=infixToPostfix(P);
    //for(int i=0; i<postexp.size();i++)
    //cout<<postexp[i]<<" ";
	//cout<<"\n"<<postexp.size()<<"\n";
    et* a = constructTree(postexp);
    int value = eval(a);
    return value;
}
		
}

void variable_exp(string p){
	string var = "";
	int i;
	for(i=0;i<p.length();i++){
		if(p[i] == 61)
			break;
		else
			var+=p[i];
	}
	int num = numerical_exp(p.substr(i+1,p.length()));
	if(validity == 1){
		
		insert(var,num);
	}
    else
    	cout<<"Invalid Expression"<<"\n";
	
	
}
void exptype(string p){
	int flag = 0;
	for(int i=0;i<p.length();i++){
		if(p[i] == '='){
			flag = 1;
			break;
		}
	}
	if(flag){
        variable_exp(p);
    }
    else{
    	int number = numerical_exp(p);
    	if(validity == 1)
    		cout<<number<<"\n";
    	else
    		cout<<"Invalid Expression"<<"\n";
    }
}


int main(){
	int q=2;
	for(int i=0;i<37;i++){
			table.push_back(NULL);
		}
		int T;
		cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<37;i++){
			table[i] = NULL;
		}
		while(n--){
			validity =1;
			string p;
			cin>>p;
			exptype(p);
		}
	}
}
