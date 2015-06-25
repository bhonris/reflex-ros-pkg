#ifndef REFLEX_DRIVER_NODE_H
#define REFLEX_DRIVER_NODE_H

#define CAL_ERROR 0.05  // Encoder delta signifying movement in calibration

void signal_handler(int signum);
void load_params(ros::NodeHandle nh);

void set_raw_positions_cb(reflex_hand::ReflexHand *rh,
                          const reflex_msgs::RawServoPositions::ConstPtr &msg);
void set_radian_positions_cb(reflex_hand::ReflexHand *rh,
                             const reflex_msgs::RadianServoPositions::ConstPtr &msg);
bool zero_tactile(std_srvs::Empty::Request &req,
                  std_srvs::Empty::Response &res);
bool zero_fingers(std_srvs::Empty::Request &req,
                  std_srvs::Empty::Response &res);

int pressure_offset(int finger, int sensor);
int update_encoder_offset(int raw_value, int last_value, int current_offset);
float calc_proximal_angle(int raw_enc_value, int offset, double zero);
float calc_motor_angle(int inversion, int raw_dyn_value, double ratio, double zero);
float calc_distal_angle(float spool, float proximal);
int calc_pressure(const reflex_hand::ReflexHandState* const state,
                  int finger, int sensor);
int calc_contact(reflex_msgs::Hand hand_msg, int finger, int sensor);
void reflex_hand_state_cb(const reflex_hand::ReflexHandState * const state);
void calibrate_tactile_sensors(const reflex_hand::ReflexHandState* const state,
                               reflex_msgs::Hand hand_msg);
void update_local_tactile_zero(const reflex_hand::ReflexHandState* const state);
void update_file_tactile_zero(const reflex_hand::ReflexHandState* const state, int finger);

#endif
