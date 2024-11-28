#include <algorithm>
#include <fstream>
using namespace std;
ifstream cin( "virus.in" );
ofstream cout( "virus.out" );
const int MAXN = 6e5 + 10;
int n, k, T;
int a[ MAXN ];
long long int t[ MAXN ];
bool check( int x )
{
    for ( int i = 1; i <= n; i++ )
    {
        t[ i ] = 2ll * T * x * i - a[ i ];
    }
    int l = k, r = k, i = k, j = k;
    while ( true )
    {
        bool fl = 0;
        while ( i > 1 and t[ i - 1 ] <= t[ r ] )
        {
            i--;
            if ( t[ i ] < t[ l ] )
            {
                l = i;
                fl = 1;
            }
        }
        while ( j < n and t[ j + 1 ] >= t[ l ] )
        {
            j++;
            if ( t[ j ] > t[ r ] )
            {
                r = j;
                fl = 1;
            }
        }
        if ( !fl )
        {
            break;
        }
    }
    if ( i > 1 or j < n )
    {
        return 0;
    }
    l = i = 1, r = j = n;
    while ( true )
    {
        bool fl = 0;
        while ( i < k and t[ i + 1 ] <= t[ r ] )
        {
            i++;
            if ( t[ i ] < t[ l ] )
            {
                l = i;
                fl = 1;
            }
        }
        while ( j > k and t[ j - 1 ] >= t[ l ] )
        {
            j--;
            if ( t[ j ] > t[ r ] )
            {
                r = j;
                fl = 1;
            }
        }
        if ( !fl )
        {
            break;
        }
    }
    return i == k and j == k;
}
int main()
{
    cin.tie( 0 );
    cin >> n >> k >> T;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[ i ];
    }
    int t = a[ k ];
    sort( a + 1, a + n + 1 );
    for ( int i = 1; i <= n; i++ )
    {
        if ( a[ i ] == t )
        {
            k = i;
            break;
        }
    }
    int l = 0, r = 1e9, ans;
    while ( l <= r )
    {
        int mid = ( l + r ) / 2;
        if ( check( mid ) )
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}