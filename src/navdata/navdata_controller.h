#ifndef __NAVDATA_CONTROLLER_H
#define __NAVDATA_CONTROLLER_H

#include "../sender.h"
#include "../com/message_drone.h"
#include "../com/at-commands.h"
#include "pcap/pcap.h"

#define DEST_IP_NAV		"127.0.0.1"
#define DEST_PORT_NAV	5554
#define IFACE           "lo" // loopback interface
#define NAVDATA_HEADER  0x55667788
#define TIME_OUT        10

//! This enumeration map bitfields to the drone state word in
//! the navdata header.
enum drone_state {
    //!< (0) ardrone is landed, (1) ardrone is flying
    fly = 1 << 0,
    //!< (0) video disable, (1) video enable
    video = 1 << 1,
    //!< (0) vision disable, (1) vision enable
    vision = 1 << 2,
    //!< (0) euler angles control, (1) angular speed control
    control = 1 << 3,
    //!< (0) altitude control inactive (1) altitude control active
    altitude = 1 << 4,
    //!< Start button stat
    user_feedback = 1 << 5,
    //!< Control command ACK : (0) None, (1) one received
    command_ack = 1 << 6,
    //!< (0) camera not ready, (1) Camera ready
    camera = 1 << 7,
    //!< Travelling mask : (0) disable, (1) enable
    travelling = 1 << 8,
    //!< USB key : (0) usb key not ready, (1) usb key ready
    usb = 1 << 9,
    //!< Navdata demo : (0) All navdata, (1) only navdata demo
    navdata_demo = 1 << 10,
    //!< (0) options sent in all or demo mode, (1) no navdata options sent
    navdata_bootstrap = 1 << 11,
    //!< (0) Ok, (1) Motors proble
    motors = 1 << 12,
    //!< Communication Lost : (1) com problem, (0) Com is ok
    com_lost = 1 << 13,
    //!< Software fault detected - user should land as quick as possible (1)
    software_fault = 1 << 14,
    //!< VBat low : (1) too low, (0) Ok
    vbat_low = 1 << 15,
    //!< User Emergency Landing : (1) User EL is ON, (0) User EL is OFF
    user_emergency = 1 << 16,
    //!< Timer elapsed : (1) elapsed, (0) not elapsed
    timer_elapsed = 1 << 17,
    //!< Magnetometer calibration state : (0) Ok, no calibration needed, (1) not ok, calibration needed
    magneto_needs_calib = 1 << 18,
    //!< Angles : (0) Ok, (1) out of range
    angles_out_of_range = 1 << 19,
    //!< (0) ok, (1) Too much wind
    wind = 1 << 20,
    //!< Ultrasonic sensor : (0) Ok, (1) deaf
    ultrasonic = 1 << 21,
    //!< Cutout system detection : (0) Not detected, (1) detected
    cutout = 1 << 22,
    //!< Version number OK : (0) a bad version number, (1) version number is OK
    navboard_version = 1 << 23,
    //!< ATCodec thread ON : (0) thread OFF (1) thread ON
    atcodec_thread = 1 << 24,
    //!< Navdata thread ON : (0) thread OFF (1) thread ON
    navdata_thread = 1 << 25,
    //!< Video thread ON : (0) thread OFF (1) thread ON
    video_thread = 1 << 26,
    //!< Acquisition thread ON : (0) thread OFF (1) thread ON
    acq_thread = 1 << 27,
    //!< CTRL watchdog : (1) delay in control execution (> 5ms), (0) control is well scheduled
    ctrl_watchdog = 1 << 28,
    //!< ADC Watchdog : (1) delay in uart2 dsr (> 5ms), (0) uart2 is good
    adc_watchdog = 1 << 29,
    //!< Communication Watchdog : (1) com problem, (0) Com is ok
    com_watchdog = 1 << 30,
    //!< Emergency landing : (0) no emergency, (1) emergency
    emergency = 1 << 31
};

//! This enumeration defines the navdata options' tags.
//! To enable a specific navdata option, write (1 << tag) in
//!   the general:navdata_options configuration parameter (while
//!   setting general:navdata_demo to FALSE).
enum option_tag {
    option_demo = 0,
    option_time,
    option_raw_measures,
    option_phys_measures,
    option_gyros_offsets,
    option_euler_angles,
    option_references,
    option_trims,
    option_rc_references,
    option_pwm,
    option_altitude,
    option_vision_raw,
    option_vision_off,
    option_vision,
    option_vision_perf,
    option_trackers_send,
    option_vision_detect,
    option_watchdog,
    option_adc_data_frame,
    option_video_stream,
    option_games,
    option_pressure_raw,
    option_magneto,
    option_wind,
    option_kalman_pressure,
    option_hdvideo_stream,
    option_wifi,
    option_cks = 0xFFFF
};

//Navdata option header
typedef struct navdata_option_t {
    uint16_t tag;
    uint16_t size;
    //uint8_t  data[];
} __attribute__ ((packed)) navdata_option_t;

/**
 * @brief Navdata structure sent over the network.
 */
typedef struct navdata_header {
    uint32_t    magic;              /*!< Always set to NAVDATA_HEADER */
    uint32_t    ardrone_state;      /*!< Bit mask built from def_ardrone_state_mask_t */
    uint32_t    sequence;           /*!< Sequence number, incremented for each sent packet */
    uint32_t    vision_defined;
    //navdata_option_t  options[1];
} __attribute__ ((packed)) navdata_header;

/*----------------------------------------------------------------------------*/
/**
 * @brief Minimal navigation data for all flights.
 */
typedef struct navdata_demo_t
{

    //!< Normally this should be 'option_demo'
    uint16_t tag;
    //!< Size of this option
    uint16_t size;
    //!< Drone's state, see option_demo_state enumeration
    uint32_t ctrl_state;
    //< Battery voltage in mV
    uint32_t vbat_flying_percentage;

    //!< Pitch in mdeg
    float theta;
    //!< Roll in mdeg
    float phi;
    //!< Yaw in mdeg
    float psi;

    //!< Altitude in cm
    int32_t altitude;

    //!< Estimated linear speeds
    float vx;
    float vy;
    float vz;

    //!< Not used
    uint32_t num_frames;

    //!< Don't use, deprecated
    uint32_t detection_camera_rot[3][3];
    uint32_t detection_camera_trans[3];
    uint32_t detection_tag_index;

    //!< Type of tag searched in detection
    uint32_t detection_camera_type;

    //!< Don't use, deprecated
    uint32_t drone_camera_rot[3][3];
    uint32_t drone_camera_trans[3];
} __attribute__ ((packed)) navdata_demo_t;

typedef struct _vector31_t {
    union {
        float v[3];
        struct {
            float x;
            float y;
            float z;
        };
    };
} vector31_t;
    
/**
 * @brief The magneto structure
 */
typedef struct _navdata_magneto_t {
    uint16_t      tag;
    uint16_t      size;

    int16_t       mx;
    int16_t       my;
    int16_t       mz;
    vector31_t    magneto_raw;       // magneto in the body frame, in mG
    vector31_t    magneto_rectified;
    vector31_t    magneto_offset;
    float         heading_unwrapped;
    float         heading_gyro_unwrapped;
    //!< heading_fusion_unwrapped seems to provide a usable value in degrees
    float         heading_fusion_unwrapped; /*!< Warning, the range is [0°,180+heading_unwrapped]U[-180+heading_unwrapped,0°] */
    char          magneto_calibration_ok;
    uint32_t      magneto_state;
    float         magneto_radius;
    float         error_mean;
    float         error_var;

} __attribute__ ((packed)) navdata_magneto_t;

/** @brief This is the structure we provide */
typedef struct Navdata
{
    navdata_header header;      /*!< The header, you can check the sequence number */
    navdata_demo_t demo;        /*!< The basic navdata */
    navdata_magneto_t magneto;  /*!< The magneto navdata */
} Navdata;


/*----------------------------------------------------------------------------*/
/* Public functions */

/** @brief This will initialize the navdata reception system (add a thread) */
void initNavdata();

/** @brief Send a value > 0 if the navdata controller is initiated (ready) */
int isControllerReady();

/** @brief This retrieves last navdata, see Navdata structure */
Navdata getNavdata();

#endif
