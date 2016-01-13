/* at-commands.h -- AT commands generation
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef AT_COMMANDS_H
#define AT_COMMANDS_H

#include "../common.h"

#define MAX_LENGTH 1024

int convert_float(float a);

char *at_ref(char *buf, int seq, int control);
char *at_pcmd(char *buf, int seq, pcmd_t pcmd);
char *at_pcmd_mag(char *buf, int seq, pcmd_mag_t pcmd, float magPsiAccuracy);
char *at_ftrim(char *buf, int seq);
char *at_calib(char *buf, int seq, ardrone_calibration_device_t id);
char *at_config(char *buf, int seq, const char *name, const char *value);
char *at_config_ids(char *buf, int seq, const char *sessionId, const char *userId, const char *appId);
char *at_comwdg(char *buf);
char *at_ackcontrol(char *buf, int seq);

#endif // AT_COMMANDS_H
