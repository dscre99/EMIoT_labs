#include <systemc-ams.h>

#include "config.h"
#include "config_converter_pv.h"
#include "lut.h"


SCA_TDF_MODULE(converter_pv)
{
    sca_tdf::sca_in<double> i_in; // Current from PV panel
    sca_tdf::sca_in<double> v_in; // Voltage from PV panel
    sca_tdf::sca_out<double> i_out; // Current generated delivered to the BUS

    SCA_CTOR(converter_pv): i_in("i_in"),
                            v_in("v_in"),
                            i_out("i_out") {};

    void set_attributes();
    void initialize();
    void processing();

    private:
        LUT lut_eta = LUT(V_CONV_PV, ETA_CONV_PV, SIZE_CONV_PV);
};
