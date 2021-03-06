#include <cstdint>
#include <modbus/modbus.h>

class IG5A
{
    public:

       

        IG5A();
         //modbus contex
        modbus_t *ctx;

        int ModbusInit(const char *device, int baud, char parity, int data_bit, int stop_bit);
        uint16_t ModbusRead(int slaveAddress, int regAddress);
        int ModbusWrite(int slaveAddress, int regAddress, uint16_t value);
        void ModbusClose(void);

        int GetFrequencyCommand();
        void SetFrequencyCommand(int frequencyCommand);

        

    
    private:
    
        int _frequencyCommand;
        //DRV group
        static const uint16_t regFrequencyCommand                = 0xA100;
        static const uint16_t regAccelTime                       = 0xA101;
        static const uint16_t regDecelTime                       = 0xA102;
        static const uint16_t regDriveMode                       = 0xA103;
        static const uint16_t regFrequencySettingMethod          = 0xA104;
        static const uint16_t regMultiStepFreq1                  = 0xA105;
        static const uint16_t regMultiStepFreq2                  = 0xA106;
        static const uint16_t regMultiStepFreq3                  = 0xA107;
        static const uint16_t regOutputCurrent                   = 0xA108;
        static const uint16_t regMotorRPM                        = 0xA109;
        static const uint16_t regInverterDCLinkVoltage           = 0xA10A;
        static const uint16_t regUserDisplaySelect               = 0xA10B;
        static const uint16_t regFaultDisplay                    = 0xA10C;
        static const uint16_t regDirectionOfMotorRotationSelect  = 0xA10D;
        static const uint16_t regDriveMode2                      = 0xA10E;
        static const uint16_t regFrequencySettingMethod2         = 0xA10F;
        static const uint16_t regPIDControlStandardValueSetting  = 0xA110;
        static const uint16_t regPIDControlFeedbackAmount        = 0xA111;
        
        //Function group 1
        static const uint16_t regJumpCode                        = 0xA200;
        static const uint16_t regForvardReverseRunDisable        = 0xA201;
        static const uint16_t regAccelPattern                    = 0xA202;      
        static const uint16_t regDecelPattern                    = 0xA203;
        static const uint16_t regStopModeSelect                  = 0xA204;
        static const uint16_t regDCBrakeStartFrequency           = 0xA208;
        static const uint16_t regDCBrakeWaitTime                 = 0xA209;
        static const uint16_t regDCBrakeVoltage                  = 0xA20A;
        static const uint16_t regDCBrakeTime                     = 0xA20B;
        static const uint16_t regDCBrakeStartVoltage             = 0xA20C;
        static const uint16_t regDCBrakeStartTime                = 0xA20D;
        static const uint16_t regTimeForMegnatizingAMotor        = 0xA20E;
        static const uint16_t regJogFrequency                    = 0xA214;
        static const uint16_t regMaxFrequency                    = 0xA215;
        static const uint16_t regBaseFrequency                   = 0xA216;
        static const uint16_t regStartFrequency                  = 0xA217;
        static const uint16_t regFrequencyHighLowLimit           = 0xA218;
        static const uint16_t regFrequencyHighLimit              = 0xA219;
        static const uint16_t regFrequencyLowLimit               = 0xA21A;
        static const uint16_t regTorqueBoostSelect               = 0xA21B;
        static const uint16_t regTorqueBoostInForvardDirection   = 0xA21C;
        static const uint16_t regTorqueBoostInReverseDirection   = 0xA21D;
        static const uint16_t regVFPattern                       = 0xA21E;
        static const uint16_t regUserVFFrequency1                = 0xA21F;
        static const uint16_t regUserVFVoltage1                  = 0xA220;
        static const uint16_t regUserVFFrequency2                = 0xA221;
        static const uint16_t regUserVFVoltage2                  = 0xA222;
        static const uint16_t regUserVFFrequency3                = 0xA223;
        static const uint16_t regUserVFVoltage3                  = 0xA224;
        static const uint16_t regUserVFFrequency4                = 0xA225;
        static const uint16_t regUserVFVoltage4                  = 0xA226;
        static const uint16_t regOutputVoltageAdjustments        = 0xA227;
        static const uint16_t regEnergySavingLevel               = 0xA228;
        static const uint16_t regElectronicThermalSelect         = 0xA232;
        static const uint16_t regElectronicThermalLevelFor1min   = 0xA233;
        static const uint16_t regElectronicThermalLevelForCont   = 0xA234;
        static const uint16_t regMotorCoolingMethod              = 0xA235;
        static const uint16_t regOverloadWarningLevel            = 0xA236;
        static const uint16_t regOverloadWarningTime             = 0xA237;
        static const uint16_t regOverloadTripSelect              = 0xA238;
        static const uint16_t regOverloadTripLevel               = 0xA239;
        static const uint16_t regOverloadtripTime                = 0xA23A;
        static const uint16_t regStallPreventionSelect           = 0xA23B;
        static const uint16_t regStallPreventionLevel            = 0xA23C;
        static const uint16_t regStallPreventionDurDecVolLimSel  = 0xA23D;
        static const uint16_t regSaveUpDownFrequencySelect       = 0xA23F;
        static const uint16_t regSaveUpDownFrequency             = 0xA240;
        static const uint16_t regUpDownModeSelect                = 0xA241;
        static const uint16_t regUpDownStepFrequency             = 0xA242;
        static const uint16_t regDrawnRunModeSelect              = 0xA246;
        static const uint16_t regDrawRate                        = 0xA247;
        
        //Function group 2
        static const uint16_t regJumpCode2                       = 0xA300;
        static const uint16_t regFaultHistory1                   = 0xA301;
        static const uint16_t regFaultHistory2                   = 0xA302;
        static const uint16_t regFaultHistory3                   = 0xA303;
        static const uint16_t regFaultHistory4                   = 0xA304;
        static const uint16_t regFaultHistory5                   = 0xA305;
        static const uint16_t regResetFaultHistory               = 0xA306;
        static const uint16_t regDwellFrequency                  = 0xA307;
        static const uint16_t regDwellTime                       = 0xA308;
        static const uint16_t regSkipFrequencySelect             = 0xA30A;
        static const uint16_t regSkipFrequencyLowLimit1          = 0xA30B;
        static const uint16_t regSkipFrequencyHiLimit1           = 0xA30C;
        static const uint16_t regSkipFrequencyLowLimit2          = 0xA30D;
        static const uint16_t regSkipFrequencyHiLimit2           = 0xA30E;
        static const uint16_t regSkipFrequencyLowLimit3          = 0xA30F;
        static const uint16_t regSkipFrequencyHiLimit3           = 0xA310;
        static const uint16_t regSCurveAccelDecelStartSide       = 0xA311;
        static const uint16_t regSCurveAccelDecelEndSide         = 0xA312;
        static const uint16_t regIOPhaseLoseProtectionSelect     = 0xA313;
        static const uint16_t regPowerOnStartSelect              = 0xA314;
        static const uint16_t regRestartAfterFaltResetSelection  = 0xA315;
        static const uint16_t regSpeedSearchSelect               = 0xA316;
        static const uint16_t regCurrentLevelDuringSpeedSreach   = 0xA317;
        static const uint16_t regPGainDuringSpeedSreach          = 0xA318;
        static const uint16_t regIGainDuringSpeedSreach          = 0xA319;
        static const uint16_t regNumberOfAutoRestartTry          = 0xA31A;
        static const uint16_t regAutoRestartTime                 = 0xA31B;
        static const uint16_t regMotorTypeSelect                 = 0xA31E;
        static const uint16_t regNumbersOfMotorPoles             = 0xA31F;
        static const uint16_t regRatedSlipFrequency              = 0xA320;
        static const uint16_t regMotorRatedCurrent               = 0xA321;
        static const uint16_t regNoLoadMotorCurrent              = 0xA322;
        static const uint16_t regMotorEfficiency                 = 0xA324;
        static const uint16_t regLoadInteriaRate                 = 0xA325;
        static const uint16_t regCarrierFrequencySelect          = 0xA327;
        static const uint16_t regControlModeSelect               = 0xA328;
        static const uint16_t regAutoTuning                      = 0xA329;
        static const uint16_t regStatorResistance                = 0xA32A;
        static const uint16_t regLeakageInductance               = 0xA32C;
        static const uint16_t regSensorlessPGain                 = 0xA32D;
        static const uint16_t regSensorlessIGain                 = 0xA32E;
        static const uint16_t regSensorlessTorqueLimit           = 0xA32F;
        static const uint16_t regPWMModeSelect                   = 0xA330;
        static const uint16_t regPIDSelect                       = 0xA331;
        static const uint16_t regPIDFBSelect                     = 0xA332;
        static const uint16_t regPGainForPID                     = 0xA333;
        static const uint16_t regIntegralTimeForPID              = 0xA334;
        static const uint16_t regDifferentialTimeForPID          = 0xA335;
        static const uint16_t regPIDModeControlSelect            = 0xA336;
        static const uint16_t regPIDOutputFrequencyHighLimit     = 0xA337;
        static const uint16_t regPIDOutputFrequencyLowLimit      = 0xA338;
        static const uint16_t regPIDStandardValueSelect          = 0xA339;
        static const uint16_t regPIDControlUnitSelect            = 0xA33A;
        static const uint16_t regPIDOutputInverse                = 0xA33B;
        static const uint16_t regSelfDiagnosticSelect            = 0xA33C;
        static const uint16_t regSleepDelayTime                  = 0xA33D;
        static const uint16_t regSleepFrequency                  = 0xA33E;
        static const uint16_t regWakeUplevel                     = 0xA33F;
        static const uint16_t regKEBDriveSelect                  = 0xA340;
        static const uint16_t regKEBActionStartLevel             = 0xA341;
        static const uint16_t regKEBActionStopLevel              = 0xA342;
        static const uint16_t regKEBActionGain                   = 0xA343;
        static const uint16_t regFrequencyReferenceForAccelDecel = 0xA346;
        static const uint16_t regAccelDecelTimeScale             = 0xA347;
        static const uint16_t regPowerOnDisplay                  = 0xA348;
        static const uint16_t regMonitoringItemSelect            = 0xA349;
        static const uint16_t regGainForMotorRPMDisplay          = 0xA34A;
        static const uint16_t regDBResistorOperatingRateLimitSel = 0xA34B;
        static const uint16_t regDBResistorOperatingRate         = 0xA34C;
        static const uint16_t regCoolingFanControl               = 0xA34D;
        static const uint16_t regOperatingMethodFanMalfunctions  = 0xA34E;
        static const uint16_t regSWVersion                       = 0xA34F;
        static const uint16_t reg2ndMotorAccelTime               = 0xA351;
        static const uint16_t reg2ndMotorDecelTime               = 0xA352;
        static const uint16_t reg2ndMotorBaseBaseFrequency       = 0xA353;
        static const uint16_t reg2ndMotorVFPattern               = 0xA354;
        static const uint16_t reg2ndMotorForwardTorqueBoost      = 0xA355;
        static const uint16_t reg2ndMotorReverseTorqueBoost      = 0xA356;
        static const uint16_t reg2ndMotorSttallPreventionLevel   = 0xA357;
        static const uint16_t reg2ndMotorElThermalLvlFor1Minute  = 0xA358;
        static const uint16_t reg2ndMotorElThermalLvlForConti    = 0xA359;
        static const uint16_t reg2ndMotorRatedCurrnet            = 0xA35A;
        static const uint16_t regParameterRead                   = 0xA35B;
        static const uint16_t regParameterWrite                  = 0xA35C;
        static const uint16_t regParameterInitialize             = 0xA35D;
        static const uint16_t regPasswordRegister                = 0xA35E;
        static const uint16_t regParameterLock                   = 0xA35F;
        
        //Input/Output Group
        static const uint16_t regJumpCodeIOGroup                 = 0xA400;
        static const uint16_t regNVInputMinVoltage               = 0xA402;
        static const uint16_t regFrequencyCorrespondingToL2      = 0xA403;
        static const uint16_t regNVInputMaxVoltage               = 0xA404;
        static const uint16_t regFrequencyCorrespondingToL4      = 0xA405;
        static const uint16_t regFilterTimeConstantForV1Input    = 0xA406;
        static const uint16_t regV1InputMinVoltage               = 0xA407;
        static const uint16_t regFrequencyCorrespondingToL7      = 0xA408;
        static const uint16_t regV1InputMaxVoltage               = 0xA409;
        static const uint16_t regFrequencyCorrespondingToL9      = 0xA40A;
        static const uint16_t regFilterTimeConstantForIInput     = 0xA40B;
        static const uint16_t regIInputMinCurrent                = 0xA40C;
        static const uint16_t regFrequencyCorrespondingToL12     = 0xA40D;
        static const uint16_t regiInputMaxCurrent                = 0xA40E;
        static const uint16_t regFrequencyCorrenspondingToL14    = 0xA40F;
        static const uint16_t regCriteriaForAnalogInpSignalLoss  = 0xA410;
        static const uint16_t regMultifunctInputTerminalP1Define = 0xA411;
        static const uint16_t regMultifunctInputTerminalP2Define = 0xA412;
        static const uint16_t regMultifunctInputTerminalP3Define = 0xA413;
        static const uint16_t regMultifunctInputTerminalP4Define = 0xA414;
        static const uint16_t regMultifunctInputTerminalP5Define = 0xA415;
        static const uint16_t regMultifunctInputTerminalP6Define = 0xA416;
        static const uint16_t regMultifunctInputTerminalP7Define = 0xA417;
        static const uint16_t regMultifunctInputTerminalP8Define = 0xA418;
        static const uint16_t regInputTerminalStatusDisplay      = 0xA419;
        static const uint16_t regOutputTerminalStatusDisplay     = 0xA41A;
        static const uint16_t regFilterTConstMultiFunInpTerminal = 0xA41B;
        static const uint16_t regMultiStepFrequency4             = 0xA41E;
        static const uint16_t regMultiStepFrequency5             = 0xA41F;
        static const uint16_t regMultiStepFrequency6             = 0xA420;
        static const uint16_t regMultiStepFrequency7             = 0xA421;
        static const uint16_t regMultiAccelTime1                 = 0xA422;
        static const uint16_t regMultiDecelTime1                 = 0xA423;
        static const uint16_t regMultiAccelTime2                 = 0xA424;
        static const uint16_t regMultiDecelTime2                 = 0xA425;
        static const uint16_t regMultiAccelTime3                 = 0xA426;
        static const uint16_t regMultiDecelTime3                 = 0xA427;
        static const uint16_t regMultiAccelTime4                 = 0xA428;
        static const uint16_t regMultiDecelTime4                 = 0xA429;
        static const uint16_t regMultiAccelTime5                 = 0xA42A;
        static const uint16_t regMultiDecelTime5                 = 0xA42B;
        static const uint16_t regMultiAccelTime6                 = 0xA42C;
        static const uint16_t regMultiDecelTime6                 = 0xA42D;
        static const uint16_t regMultiAccelTime7                 = 0xA42E;
        static const uint16_t regMultiDecelTime7                 = 0xA42F;
        static const uint16_t regAnalogOutputItemSelect          = 0xA432;
        static const uint16_t regAnalogOutputLevelAdjustment     = 0xA433;
        static const uint16_t regFrequencyDetectionLevel         = 0xA434;
        static const uint16_t regFrequencyDetectionBandwith      = 0xA435;
        static const uint16_t regMultifuncOutputTerminalSelect   = 0xA436;
        static const uint16_t regMultifunctionRelaySelect        = 0xA437;
        static const uint16_t regFaultRelayOutput                = 0xA438;
        static const uint16_t regOutTermSelWhenCommErrorOccurs   = 0xA439;
        static const uint16_t regCommunicationProtocolSelect     = 0xA43B;
        static const uint16_t regInverterNumber                  = 0xA43C;
        static const uint16_t regBaudRate                        = 0xA43D;
        static const uint16_t regDriveModeSelAfterLossOfFreqCmd  = 0xA43E;
        static const uint16_t regWaitTimeAfterLossOfFreqCmd      = 0xA43F;
        static const uint16_t regCommunicationTimeSetting        = 0xA440;
        static const uint16_t regParityStopBitSetting            = 0xA441;
        static const uint16_t regReadAddressRegister1            = 0xA442;
        static const uint16_t regReadAddressRegister2            = 0xA443;
        static const uint16_t regReadAddressRegister3            = 0xA444;
        static const uint16_t regReadAddressRegister4            = 0xA445;
        static const uint16_t regReadAddressRegister5            = 0xA446;
        static const uint16_t regReadAddressRegister6            = 0xA447;
        static const uint16_t regReadAddressRegister7            = 0xA448;
        static const uint16_t regReadAddressRegister8            = 0xA449;
        static const uint16_t regWriteAddressRegister1           = 0xA44A;
        static const uint16_t regWriteAddressRegister2           = 0xA44B;
        static const uint16_t regWriteAddressRegister3           = 0xA44C;
        static const uint16_t regWriteAddressRegister4           = 0xA44D;
        static const uint16_t regWriteAddressRegister5           = 0xA44E;
        static const uint16_t regWriteAddressRegister6           = 0xA44F;
        static const uint16_t regWriteAddressRegister7           = 0xA450;
        static const uint16_t regWriteAddressRegister8           = 0xA451;
        static const uint16_t regBreakOpenCurrent                = 0xA452;
        static const uint16_t regBreakOpenDelayTime              = 0xA453;
        static const uint16_t regBrakeOpenFXFrequency            = 0xA454;
        static const uint16_t regBreakOpenRXFrequency            = 0xA455;
        static const uint16_t regBreakCloseDelayTime             = 0xA456;
        static const uint16_t regBreakCloseFrequency             = 0xA457;
        
        
        
        
};
