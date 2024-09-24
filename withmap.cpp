#include<bits/stdc++.h>
using namespace std;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define rep(i,a,b) for(ll i=a;i<b;i++)
 
 
ll mod=1e9+7;//3314192745739;
 
ll sub(ll a,ll b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}
ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}
 
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //srand(time(NULL));
    
    string s;
    cin>>s;
    ll n=s.size();
    
    ll mxn=1e5+5;
    vl prime={31,37,43};
    vvl pw(3,vl(mxn,1));
    
    rep(i,0,3)
    {
        rep(j,1,mxn)
        pw[i][j]=mul(pw[i][j-1],prime[i]);
    }
    
    ll l=1,r=n-1;
    ll len=-1,start=-1;
    
    while(l<=r)
    {
        ll m=l+r;
        m>>=1;
        
        ll f=0;
        map<ll,bool> mp[3];
        vl hash(3,0);
        rep(i,0,3)
        {
            rep(j,0,m)
            hash[i]=add(hash[i], mul(s[j]-'a'+1, pw[i][m-j-1]));
        }
        rep(i,0,3)
        mp[i][hash[i]]=1;
        
        rep(i,m,n)
        {
            ll ct=0;
            rep(p,0,3)
            {
                hash[p]=mul(hash[p],prime[p]);
                hash[p]=sub(hash[p], mul(s[i-m]-'a'+1,pw[p][m]));
                hash[p]=add(hash[p], s[i]-'a'+1);
                if(mp[p].find(hash[p])!=mp[p].end())
                ct++;
                else
                mp[p][hash[p]]=1;
            }
            if(ct==3)
            {start=i-m+1,f=1;break;}
        }
        
        if(f)
        len=m,l=m+1;
        else
        r=m-1;
    }
    
    //cout<<len<<"    ";
    
    if(len==-1)
    cout<<-1;
    else
    rep(i,start,start+len)
    cout<<s[i];
    
    return 0;
}
