#include<bits/stdc++.h>
using namespace std;

struct etree
{
    string value;
    etree* left, *right;
};
//This is the function for getting preference order of operators
int pref(string c)
{
    if(c == "^")
    return 3;
    else if(c == "*" || c == "/")
    return 2;
    else if(c == "+" || c == "-")
    return 1;
    else
    return -1;
}
//This is the function to convert the given infix to postfix form
vector<string> infixToPostfix(vector<string> s)
{
    std::stack<string> st;
    st.push("N");
    int l = s.size();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(s[i]!="(" && s[i]!=")" && s[i]!="+" && s[i]!="*" && s[i]!="-" && s[i]!="/") {
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
            while(st.top() != "N" && pref(s[i]) <= pref(st.top()))
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
//This is the function to check whether the string element is an operator or not operator
bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

etree* newNode(string node_value)
{
    etree *tmp = new etree;
    tmp->left = tmp->right = NULL;
    tmp->value = node_value;
    return tmp;
};

// Returns root of constructed tree for given
// postfix expression
etree* createTree(vector<string> postfix)
{
    stack<etree *> st;
    etree *t, *t1, *t2;

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
        else // i.e if it is an operator
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

int eval(etree* a){
	if(a->left==NULL&&a->right==NULL)
		return stoi(a->value);
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
}

int main()
{
    string exp;
	cin>>exp;
	vector<string> P;
	string temp="";

	for(int i=0; i<exp.length();i++)
	{
		if(exp[i]>=48 && exp[i]<=57)
		{
          temp+=exp[i];
		}
		else
		{
             P.push_back(temp);
            temp=""; temp+=exp[i];
              P.push_back(temp);
            temp="";
		}

	}
    P.push_back(temp);
    vector<string> postexp=infixToPostfix(P);
    etree* a = createTree(postexp);
    int val = eval(a);
    cout<<val;
}
