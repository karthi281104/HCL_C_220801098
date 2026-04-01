#include<iostream>

using namespace std;

enum Role
{
    ROLE_USER   = 1<<0,
    ROLE_EDITOR = 1<<1,
    ROLE_ADMIN  = 1<<2
};

enum Permission
{
    PERM_READ  = 1<<0,
    PERM_WRITE = 1<<1,
    PERM_EXEC  = 1<<2
};

class roles_permissions
{
    public:
    roles_permissions()
    {
        int roles = ROLE_USER | ROLE_EDITOR;
        int perms = PERM_READ | PERM_WRITE;

        cout<<"roles bitmask: "<<roles<<"\n";
        cout<<"perms bitmask: "<<perms<<"\n";

        cout<<"has ROLE_ADMIN? "<<((roles & ROLE_ADMIN) ? "yes" : "no")<<"\n";
        cout<<"has PERM_WRITE? "<<((perms & PERM_WRITE) ? "yes" : "no")<<"\n";

        roles |= ROLE_ADMIN;
        cout<<"after adding admin, roles bitmask: "<<roles<<"\n";
        cout<<"has ROLE_ADMIN? "<<((roles & ROLE_ADMIN) ? "yes" : "no")<<"\n";
    }
};

int main()
{
    roles_permissions r1;
}
