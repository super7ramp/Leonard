#include <stdio.h>
#include "../sender.h"

int main()
{
    printf("[Test sender]\n");

    if (initialize_socket() != 0)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        if (send_message("test") != 0)
            printf("[FAILED] Message sending failed\n");
        else
            printf("[SUCCESS] Message was sent!\n");
    }

    return 0;
}
