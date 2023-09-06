#include<iostream>
#include <vector>

#define print(x) std::cout<<x<<std::endl
void print_v(std::vector<std::string> v)
{
    for(std::string i: v)
    {
        
        std::cout<<i<<std::endl;
    }
}
void print_ve(std::vector<int> v)
{

    for(int i: v)
    {
        std::cout<<i<<", "<<std::endl;
    }
}
int depthcheck(std::vector<std::string> v,int n,int m, int i)
{
    std::string t("i");
    std::string k("k");
    std::string a("a");
    int check = 0;
    
    for(++i; i<m; i++ )
    {
        
        for(int q=0; q<n; q++)
        {
            std::string temp;
            temp = v[q][i];
            
            if(temp == t)
            {
                check+=1;

                break;
            }
        }
        if(check>=1)
        {break;}
    }
    
    for(++i; i<m; i++ )
    {
        for(int q=0; q<n; q++)
        {
            std::string temp;
            temp = v[q][i];
            
            if(temp == k)
            {
                check+=1;
           
                break;
            }
        }
        if(check>=2) break;
    }

    for(++i; i<m; i++ )
    {
        for(int q=0; q<n; q++)
        {
            std::string temp;
            temp = v[q][i];
            
            if(temp == a)
            {
                check+=1;
                break;
            }
        }
        if (check>=3) break;
    }
    if(check >=3)
    {
        return 1;
    }
    return 0;
}

int check(std::vector<std::string> v,int n,int m)
{
    std::vector<int> col;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::string v1("v");
            std::string v2 ;
            v2 = v[j][i];
            if(v1 == v2)
            {
                col.push_back(i);
            }
        }
    }
    for(int i: col)
    {
        if(depthcheck(v,n,m,i))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t=0, n=0, m=0;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n>>m;
        std::vector<std::string> carpet;
        std::string temp = "";
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<m;i++)
            {
                char temp_i;
                std::cin>>temp_i;
                temp += temp_i;
            }
            carpet.push_back(temp);
            temp = "";
        }
        int i = check(carpet, n, m);
        if (i)
        {
            std::cout<<"YES"<<std::endl;
        }
        else{
            std::cout<<"NO"<<std::endl;
        }
    }
    return 0;
}