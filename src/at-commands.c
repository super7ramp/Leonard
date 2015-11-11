#include <stdio.h>
#include "at-commands.h"

char *at_ref(char *buf, int seq, int control)
{
    if (buf != NULL)
        sprintf(buf, "AT*REF=%d,%d\r", seq, control);
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_pcmd(char *buf, int seq, pcmd_t pcmd)
{
    if (buf != NULL)
    {
        sprintf(buf, "AT*PCMD=%d,%d,%f,%f,%f,%f,%f\r",
                seq,
                pcmd.progressive,
                pcmd.lrTilt,
                pcmd.fbTilt,
                pcmd.verticalSpeed,
                pcmd.angularSpeed,
                pcmd.magPsi);
    }
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_pcmd_mag(char *buf, int seq, pcmd_t pcmd, float magPsiAccuracy)
{
    if (buf != NULL)
    {
        sprintf(buf, "AT*PCMD_MAG=%d,%d,%f,%f,%f,%f,%f,%f\r",
                seq,
                pcmd.progressive,
                pcmd.lrTilt,
                pcmd.fbTilt,
                pcmd.verticalSpeed,
                pcmd.angularSpeed,
                pcmd.magPsi,
                magPsiAccuracy);
    }
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_ftrim(char *buf, int seq)
{
    if (buf != NULL)
        sprintf(buf, "AT*FTRIM=%d\r", seq);
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_calib(char *buf, int seq, ardrone_calibration_device_t id)
{
    if (buf != NULL)
        sprintf(buf, "AT*CALIB=%d,%d\r", seq, id);
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_config(char *buf, int seq, const char *name, const char *value)
{
   if (buf != NULL)
      sprintf(buf, "AT*CONFIG=%d,\"%s\",\"%s\"\r", seq, name, value);
   else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
   return buf;
}

char *at_config_ids(char *buf, int seq, const char *sessionId, const char *userId, const char *appId)
{
    if (buf != NULL)
        sprintf(buf, "AT*CONFIG_IDS=%d,\"%s\",\"%s\",\"%s\"\r", seq, sessionId, userId, appId);
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}

char *at_comwdg(char *buf)
{
    if (buf != NULL)
        sprintf(buf, "AT*COMWDG=1\r");
    else
        fprintf(stderr, "[%s:%d] Error: Buffer is null!", __FILE__, __LINE__);
    return buf;
}
