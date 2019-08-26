#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> chart;

struct et 
{ 
    string value; 
    et* left, *right; 
}; 

int prec(string c) 
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

bool isOperator(string c) 
{ 
    if (c.length()==1 && (c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^") )
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
  

vector<string> infixToPostfix(vector<string> s) 
{ 
    stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
         
        if(!isOperator(s[i]) && s[i]!="" && s[i]!="(" && s[i]!=")") 
         ns.push_back(s[i]); 
        
        else if(s[i] == "(")   
        st.push("("); 
          
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
                
                
            if(c!="" && c!="(" && c!=")")ns.push_back(c); 
              
               
            } 
            if(st.top() == "(") 
            { 
                st.pop();  
            } 
        } 
           
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                if(s[i]=="^" && st.top()=="^") break;
                string c = st.top(); 
                st.pop(); 
                
                if(c!="" && c!="(" && c!=")")ns.push_back(c); 
                
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != "N") 
    { 
                string c = st.top(); 
                st.pop(); 
                if(c!="" && c!="(" && c!=")")ns.push_back(c);  
              
    } 
      
    return ns;
  
} 
 
et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    for (int i=0; i<postfix.size(); i++) 
    { 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
  
            t1 = st.top(); 
            st.pop();      
            t2 = st.top(); 
            st.pop(); 
  
            t->right = t1; 
            t->left = t2; 
  
            st.push(t); 
        } 
    } 
   
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int eval(et * root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    {
        try { return stoi(root->value);
        }
       catch(...){
        if(chart.find(root->value)!=chart.end()) return chart[root->value];
        else 
        { return INT_MAX;}
        
     }
    }
    int l=eval(root->left);
    int r=eval(root->right);
    if(l==INT_MAX || r==INT_MAX) return INT_MAX;
    if(root->value=="+") return l+r;
    else if(root->value=="-") return l-r;
    else if(root->value=="*") return l*r;
    else if(root->value=="/") return l/r;
    else return pow(l,r);
}
vector<string> goodstring(string s)
{
    int flag=0;
         int mark=0;
         string temp="";
         vector<string> str;
    for(int i=0; i<s.length();i++)
    {
        if( (s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
        {
            temp+=s[i];
        }
        
        else
        {
            if((temp=="" && s[i]=='-' && i==0) || (temp=="" && s[i]=='-' && s[i-1]!=')' ) ) //check if unary minus is thee
                {
                    str.push_back("("); 
                    str.push_back("0"); 
                    str.push_back("-"); 
                    if(s[i+1]=='(') flag+=1; //expression has minus on it
                    else mark+=1; //just a number has minus on it
                }
            else{
                  if(temp!="") str.push_back(temp);  //to push number or variablke formed 
                  
                  while(mark>0) { 
                      str.push_back(")"); // close as many unary minus were opened
                      mark--;
                  }
                  
                  temp=""; temp+=s[i]; //to convert the operator or bracket  to string 
                  if(temp!="") str.push_back(temp); // then push to vstring
                  
                  if(temp==")") { //as exp ends put the bracket close
                      if(flag--)
                         str.push_back(")"); 
                  }
                }
                temp=""; //renew tmp
        }
    }
    
    str.push_back(temp);
    if(mark>0) str.push_back(")");
    return str;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        chart.clear();
      while(n--)
      {
         string s;
         cin>>s;
         vector<string> str;
         string temp="";
         
         if(s.find("=") == std::string::npos )
         {
    
          vector<string> str= goodstring(s);
          vector<string> postexp=infixToPostfix(str);

         struct et* root=constructTree(postexp);
         int ans = eval(root);
         if(ans != INT_MAX)
         cout<<ans<<endl;
         else cout<<"CANT BE EVALUATED"<<endl;
         }

         else
         {
             int k= s.find("=");
             string s1=s.substr(0,k);
             string s2=s.substr(k+1);
             vector<string> str= goodstring(s2);
           vector<string> postexp=infixToPostfix(str);

          struct et* root=constructTree(postexp);
         int ans = eval(root);
         if(chart.find(s1)!= chart.end() )
         {
          if(ans != INT_MAX)
          chart[s1]=ans;
          else cout<<"CANT BE EVALUATED"<<endl;
         }
         else
         {
           if(ans != INT_MAX)
           chart.insert(make_pair(s1,ans));
           else cout<<"CANT BE EVALUATED"<<endl;
          }
        }
        } 
    }
}
