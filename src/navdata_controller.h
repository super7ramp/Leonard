#ifndef __NAVDATA_CONTROLLER_H
#define __NAVDATA_CONTROLLER_H

#include "sender.h"
#include <Maths/maths.h>
#include <Maths/matrices.h>
#include <pcap.h>
//#include "../lib/libpcap/include/pcap/pcap.h"

#define NAV_IP_NAV		"127.0.0.1"
#define NAV_PORT_NAV	5554
#define IFACE   "lo" // loopback interface
#define NAVDATA_HEADER  0x55667788

//! This enumeration defines the navdata options' tags.
    //! To enable a specific navdata option, write (1 << tag) in
    //!   the general:navdata_options configuration parameter (while
    //!   setting general:navdata_demo to FALSE).
enum option_tag {
	option_demo = 0,
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
}navdata_option_t;

/**
 * @brief Navdata structure sent over the network.
 */
typedef struct navdata_t {
  uint32_t    magic;			/*!< Always set to NAVDATA_HEADER */
  uint32_t    ardrone_state;    /*!< Bit mask built from def_ardrone_state_mask_t */
  uint32_t    sequence;         /*!< Sequence number, incremented for each sent packet */
  uint32_t    vision_defined;

  navdata_option_t  options[1];
}navdata_t;

/*----------------------------------------------------------------------------*/
/**
 * @brief Minimal navigation data for all flights.
 */
typedef struct navdata_demo_t {
  uint16_t    tag;					  /*!< Navdata block ('option') identifier */
  uint16_t    size;					  /*!< set this to the size of this structure */

  uint32_t    ctrl_state;             /*!< Flying state (landed, flying, hovering, etc.) defined in CTRL_STATES enum. */
  uint32_t    vbat_flying_percentage; /*!< battery voltage filtered (mV) */

  float32_t   theta;                  /*!< UAV's pitch in milli-degrees */
  float32_t   phi;                    /*!< UAV's roll  in milli-degrees */
  float32_t   psi;                    /*!< UAV's yaw   in milli-degrees */

  int32_t     altitude;               /*!< UAV's altitude in centimeters */

  float32_t   vx;                     /*!< UAV's estimated linear velocity */
  float32_t   vy;                     /*!< UAV's estimated linear velocity */
  float32_t   vz;                     /*!< UAV's estimated linear velocity */

  uint32_t    num_frames;			  /*!< streamed frame index */ // Not used -> To integrate in video stage.

  // Camera parameters compute by detection
  matrix33_t  detection_camera_rot;   /*!<  Deprecated ! Don't use ! */
  vector31_t  detection_camera_trans; /*!<  Deprecated ! Don't use ! */
  uint32_t	  detection_tag_index;    /*!<  Deprecated ! Don't use ! */

  uint32_t	  detection_camera_type;  /*!<  Type of tag searched in detection */

  // Camera parameters compute by drone
  matrix33_t  drone_camera_rot;		  /*!<  Deprecated ! Don't use ! */
  vector31_t  drone_camera_trans;	  /*!<  Deprecated ! Don't use ! */
}navdata_demo_t;

//! Vision detection navdata option
typedef struct vision_detect {
    //!< Normally this should be 'option_vision_detect'
    uint16_t tag;
    //!< Size of this struct
    uint16_t size;

    uint32_t nb_detected;
    uint32_t type[4];
    uint32_t xc[4];
    uint32_t yc[4];
    uint32_t width[4];
    uint32_t height[4];
    uint32_t dist[4];
    float orientation_angle[4];
    float rotation[3][3][4];
    float translation[3][4];
    uint32_t camera_source[4];
}vision_detect;

#endif
