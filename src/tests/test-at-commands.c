/* test-at-commands.c -- Test program for AT commands
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "../at-commands.h"

#define BUFLEN 512
int main()
{
    char buffer[512];
    int n = 0; // seq number

    printf("[Test REF]\n");
    printf("%s\n", at_ref(buffer, n++, 1));

    printf("[Test FTRIM]\n");
    printf("%s\n", at_ftrim(buffer, n++));

    printf("[Test AT_PCMD]\n");
    pcmd_t command;
    command.progressive = 1;
    command.lrTilt = 0.9;
    command.fbTilt = 0.8;
    command.verticalSpeed = 0.7;
    command.angularSpeed = 0.6;
    printf("%s\n", at_pcmd(buffer, n++, command));

    printf("[Test CALIB]\n%s\n", at_calib(buffer, n++, ARDRONE_CALIBRATION_DEVICE_NUMBER));

    printf("[Test CONFIG]\n%s\n", at_config(buffer, n++, "NAME", "42"));

    printf("[Test CONFIG_IDS]\n%s\n", at_config_ids(buffer, n++, "SESSION_ID", "USER_ID", "APP_ID"));

    printf("[Test COMWDG]\n%s\n", at_comwdg(buffer));

    return 0;
}
