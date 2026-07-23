#include "user.h"
#include "demos.h"

int main(void)
{
    User user =
    {
        "User",
        0,
        0,
        0,
        VIP
    };

    registerUser(&user);
    demoInput();

    showUser(&user);

    demoBasicTypes();
    demoArrays();
    demoLoops();
    demoPointers(&user);
    demoDynamicMemory();

    return 0;
}