// Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  This file is automatically generated
//               These definitions are tied to a particular hardware layout


#ifndef _TX_RATE_SETTING_H_
#define _TX_RATE_SETTING_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	tx_antenna_sector_ctrl[23:0], chain_mask[27:24], paprd_chain_mask[31:28]
//	1	pkt_type[2:0], reserved_1a[3], nss[6:4], rate_mcs[10:7], tpc_init_pwr_cfg[13:11], dpd_enable[14], tx_pwr[21:15], stbc[22], ldpc[23], sgi[24], tx_pwr_sec80[31:25]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_RATE_SETTING 2

struct tx_rate_setting {
    volatile uint32_t tx_antenna_sector_ctrl          : 24, //[23:0]
                      chain_mask                      :  4, //[27:24]
                      paprd_chain_mask                :  4; //[31:28]
    volatile uint32_t pkt_type                        :  3, //[2:0]
                      reserved_1a                     :  1, //[3]
                      nss                             :  3, //[6:4]
                      rate_mcs                        :  4, //[10:7]
                      tpc_init_pwr_cfg                :  3, //[13:11]
                      dpd_enable                      :  1, //[14]
                      tx_pwr                          :  7, //[21:15]
                      stbc                            :  1, //[22]
                      ldpc                            :  1, //[23]
                      sgi                             :  1, //[24]
                      tx_pwr_sec80                    :  7; //[31:25]
};

/*

tx_antenna_sector_ctrl
			
			Sectored transmit antenna
			
			<legal all>

chain_mask
			
			Chain mask to support up to 4 antennas.  <legal: 1-15>

paprd_chain_mask
			
			Chain mask for the PA predistortion function.  <legal:
			0,1,2,4,8> 

pkt_type
			
			Packet type:
			
			<enum_typedef tx_phy_desc pkt_type>
			
			<enum 0     dot11a>
			
			<enum 1     dot11b>
			
			<enum 2     dot11n_mm>
			
			<enum 3     dot11ac>
			
			<enum 4     dot11n_gf>Note: HT Greenfield packet type is
			not supported
			
			<legal 0-4>

reserved_1a
			
			<legal 0>

nss
			
			Number of spatial streams.
			
			<enum 0     1_spatial_stream>
			
			<enum 1     2_spatial_streams>
			
			<enum 2     3_spatial_streams>
			
			<enum 3     4_spatial_streams>
			
			<legal 0-3>

rate_mcs
			
			When pkt_type indicates dot11b or dot11a:
			
			This field is the rate:
			
			For Packet type == 0 (dot11a)
			
			0: OFDM 48 Mbps
			
			1: OFDM 24 Mbps
			
			2: OFDM 12 Mbps
			
			3: OFDM 6 Mbps
			
			4: OFDM 54 Mbps
			
			5: OFDM 36 Mbps
			
			6: OFDM 18 Mbps
			
			7: OFDM 9 Mbps
			
			For Packet type ==1 (dot11b => cck)
			
			0: CCK 11 Mbps Long
			
			1: CCK 5.5 Mbps Long
			
			2: CCK 2 Mbps Long
			
			3: CCK 1 Mbps Long
			
			4: CCK 11 Mbps Short
			
			5: CCK 5.5 Mbps Short
			
			6: CCK 2 Mbps Short
			
			
			
			When pkt_type indicates ht_mixed_mode or vht:
			
			This field is the MCS.
			
			For Packet type == 2 (dot11n_mm)
			
			0: HT MCS 0 (BPSK 1/2)
			
			1: HT MCS 1 (QPSK 1/2)
			
			2: HT MCS 2 (QPSK 3/4)
			
			3: HT MCS 3 (16-QAM 1/2)
			
			4: HT MCS 4 (16-QAM 3/4)
			
			5: HT MCS 5 (64-QAM 2/3)
			
			6: HT MCS 6 (64-QAM 3/4)
			
			7: HT MCS 7 (64-QAM 5/6)
			
			Note: to get higher MCS's use the nss field to indicate
			the number of streams.
			
			For Packet type == 3 (dot11ac)
			
			0: VHT MCS 0 (BPSK 1/2)
			
			1: VHT MCS 1 (QPSK 1/2)
			
			2: VHT MCS 2 (QPSK 3/4)
			
			3: VHT MCS 3 (16-QAM 1/2)
			
			4: VHT MCS 4 (16-QAM 3/4)
			
			5: VHT MCS 5 (64-QAM 2/3)
			
			6: VHT MCS 6 (64-QAM 3/4)
			
			7: VHT MCS 7 (64-QAM 5/6)
			
			8: VHT MCS 8 (256-QAM 3/4)
			
			9: VHT MCS 9 (256-QAM 5/6)
			
			Note there are several illegal VHT rates due to
			fractional number of bits per symbol.  Below are the illegal
			rates for 4 streams and lower:
			
			20 MHz, 1 stream, MCS 9
			
			20 MHz, 2 stream, MCS 9
			
			20 MHz, 4 stream, MCS 9
			
			80 MHz, 3 stream, MCS 6
			
			160 MHz, 3 stream, MCS 9 (Unsupported)
			
			160 MHz, 4 stream, MCS 7 (Unsupported)
			
			Although the above rates are illegal according to the
			standard, the above rates are supported for LDPC encoding.
			
			<legal 0-9>

tpc_init_pwr_cfg
			
			Initial analog gain and PA configuration setting where 0
			has the highest power consumption and best EVM,  and 4 has
			the lowest power consumption and worst EVM <legal 0-4>

dpd_enable
			
			DPD enable control
			
			
			
			This is needed on a per packet basis
			
			<enum 0     dpd_off> DPD profile not applied to current
			packet
			
			<enum 1     dpd_on> DPD profile applied to current
			packet if available
			
			<legal 0-1>

tx_pwr
			
			Transmit Power (signed value) in units of 0.5 dBm <legal
			all>

stbc
			
			When set, use STBC transmission rates

ldpc
			
			When set, use LDPC transmission rates

sgi
			
			Field only valid when pkt type is HT or VHT.
			
			When set, use short Guard interval transmission.

tx_pwr_sec80
			
			Transmit Power (signed value) in units of 0.5 dBm for
			second segment. Used to control tx power of sec80 channel in
			80+80. Should be set to same value as tx_pwr for all other
			modes. <legal all>
*/


/* Description		TX_RATE_SETTING_0_TX_ANTENNA_SECTOR_CTRL
			
			Sectored transmit antenna
			
			<legal all>
*/
#define TX_RATE_SETTING_0_TX_ANTENNA_SECTOR_CTRL_OFFSET              0x00000000
#define TX_RATE_SETTING_0_TX_ANTENNA_SECTOR_CTRL_LSB                 0
#define TX_RATE_SETTING_0_TX_ANTENNA_SECTOR_CTRL_MASK                0x00ffffff

/* Description		TX_RATE_SETTING_0_CHAIN_MASK
			
			Chain mask to support up to 4 antennas.  <legal: 1-15>
*/
#define TX_RATE_SETTING_0_CHAIN_MASK_OFFSET                          0x00000000
#define TX_RATE_SETTING_0_CHAIN_MASK_LSB                             24
#define TX_RATE_SETTING_0_CHAIN_MASK_MASK                            0x0f000000

/* Description		TX_RATE_SETTING_0_PAPRD_CHAIN_MASK
			
			Chain mask for the PA predistortion function.  <legal:
			0,1,2,4,8> 
*/
#define TX_RATE_SETTING_0_PAPRD_CHAIN_MASK_OFFSET                    0x00000000
#define TX_RATE_SETTING_0_PAPRD_CHAIN_MASK_LSB                       28
#define TX_RATE_SETTING_0_PAPRD_CHAIN_MASK_MASK                      0xf0000000

/* Description		TX_RATE_SETTING_1_PKT_TYPE
			
			Packet type:
			
			<enum_typedef tx_phy_desc pkt_type>
			
			<enum 0     dot11a>
			
			<enum 1     dot11b>
			
			<enum 2     dot11n_mm>
			
			<enum 3     dot11ac>
			
			<enum 4     dot11n_gf>Note: HT Greenfield packet type is
			not supported
			
			<legal 0-4>
*/
#define TX_RATE_SETTING_1_PKT_TYPE_OFFSET                            0x00000004
#define TX_RATE_SETTING_1_PKT_TYPE_LSB                               0
#define TX_RATE_SETTING_1_PKT_TYPE_MASK                              0x00000007

/* Description		TX_RATE_SETTING_1_RESERVED_1A
			
			<legal 0>
*/
#define TX_RATE_SETTING_1_RESERVED_1A_OFFSET                         0x00000004
#define TX_RATE_SETTING_1_RESERVED_1A_LSB                            3
#define TX_RATE_SETTING_1_RESERVED_1A_MASK                           0x00000008

/* Description		TX_RATE_SETTING_1_NSS
			
			Number of spatial streams.
			
			<enum 0     1_spatial_stream>
			
			<enum 1     2_spatial_streams>
			
			<enum 2     3_spatial_streams>
			
			<enum 3     4_spatial_streams>
			
			<legal 0-3>
*/
#define TX_RATE_SETTING_1_NSS_OFFSET                                 0x00000004
#define TX_RATE_SETTING_1_NSS_LSB                                    4
#define TX_RATE_SETTING_1_NSS_MASK                                   0x00000070

/* Description		TX_RATE_SETTING_1_RATE_MCS
			
			When pkt_type indicates dot11b or dot11a:
			
			This field is the rate:
			
			For Packet type == 0 (dot11a)
			
			0: OFDM 48 Mbps
			
			1: OFDM 24 Mbps
			
			2: OFDM 12 Mbps
			
			3: OFDM 6 Mbps
			
			4: OFDM 54 Mbps
			
			5: OFDM 36 Mbps
			
			6: OFDM 18 Mbps
			
			7: OFDM 9 Mbps
			
			For Packet type ==1 (dot11b => cck)
			
			0: CCK 11 Mbps Long
			
			1: CCK 5.5 Mbps Long
			
			2: CCK 2 Mbps Long
			
			3: CCK 1 Mbps Long
			
			4: CCK 11 Mbps Short
			
			5: CCK 5.5 Mbps Short
			
			6: CCK 2 Mbps Short
			
			
			
			When pkt_type indicates ht_mixed_mode or vht:
			
			This field is the MCS.
			
			For Packet type == 2 (dot11n_mm)
			
			0: HT MCS 0 (BPSK 1/2)
			
			1: HT MCS 1 (QPSK 1/2)
			
			2: HT MCS 2 (QPSK 3/4)
			
			3: HT MCS 3 (16-QAM 1/2)
			
			4: HT MCS 4 (16-QAM 3/4)
			
			5: HT MCS 5 (64-QAM 2/3)
			
			6: HT MCS 6 (64-QAM 3/4)
			
			7: HT MCS 7 (64-QAM 5/6)
			
			Note: to get higher MCS's use the nss field to indicate
			the number of streams.
			
			For Packet type == 3 (dot11ac)
			
			0: VHT MCS 0 (BPSK 1/2)
			
			1: VHT MCS 1 (QPSK 1/2)
			
			2: VHT MCS 2 (QPSK 3/4)
			
			3: VHT MCS 3 (16-QAM 1/2)
			
			4: VHT MCS 4 (16-QAM 3/4)
			
			5: VHT MCS 5 (64-QAM 2/3)
			
			6: VHT MCS 6 (64-QAM 3/4)
			
			7: VHT MCS 7 (64-QAM 5/6)
			
			8: VHT MCS 8 (256-QAM 3/4)
			
			9: VHT MCS 9 (256-QAM 5/6)
			
			Note there are several illegal VHT rates due to
			fractional number of bits per symbol.  Below are the illegal
			rates for 4 streams and lower:
			
			20 MHz, 1 stream, MCS 9
			
			20 MHz, 2 stream, MCS 9
			
			20 MHz, 4 stream, MCS 9
			
			80 MHz, 3 stream, MCS 6
			
			160 MHz, 3 stream, MCS 9 (Unsupported)
			
			160 MHz, 4 stream, MCS 7 (Unsupported)
			
			Although the above rates are illegal according to the
			standard, the above rates are supported for LDPC encoding.
			
			<legal 0-9>
*/
#define TX_RATE_SETTING_1_RATE_MCS_OFFSET                            0x00000004
#define TX_RATE_SETTING_1_RATE_MCS_LSB                               7
#define TX_RATE_SETTING_1_RATE_MCS_MASK                              0x00000780

/* Description		TX_RATE_SETTING_1_TPC_INIT_PWR_CFG
			
			Initial analog gain and PA configuration setting where 0
			has the highest power consumption and best EVM,  and 4 has
			the lowest power consumption and worst EVM <legal 0-4>
*/
#define TX_RATE_SETTING_1_TPC_INIT_PWR_CFG_OFFSET                    0x00000004
#define TX_RATE_SETTING_1_TPC_INIT_PWR_CFG_LSB                       11
#define TX_RATE_SETTING_1_TPC_INIT_PWR_CFG_MASK                      0x00003800

/* Description		TX_RATE_SETTING_1_DPD_ENABLE
			
			DPD enable control
			
			
			
			This is needed on a per packet basis
			
			<enum 0     dpd_off> DPD profile not applied to current
			packet
			
			<enum 1     dpd_on> DPD profile applied to current
			packet if available
			
			<legal 0-1>
*/
#define TX_RATE_SETTING_1_DPD_ENABLE_OFFSET                          0x00000004
#define TX_RATE_SETTING_1_DPD_ENABLE_LSB                             14
#define TX_RATE_SETTING_1_DPD_ENABLE_MASK                            0x00004000

/* Description		TX_RATE_SETTING_1_TX_PWR
			
			Transmit Power (signed value) in units of 0.5 dBm <legal
			all>
*/
#define TX_RATE_SETTING_1_TX_PWR_OFFSET                              0x00000004
#define TX_RATE_SETTING_1_TX_PWR_LSB                                 15
#define TX_RATE_SETTING_1_TX_PWR_MASK                                0x003f8000

/* Description		TX_RATE_SETTING_1_STBC
			
			When set, use STBC transmission rates
*/
#define TX_RATE_SETTING_1_STBC_OFFSET                                0x00000004
#define TX_RATE_SETTING_1_STBC_LSB                                   22
#define TX_RATE_SETTING_1_STBC_MASK                                  0x00400000

/* Description		TX_RATE_SETTING_1_LDPC
			
			When set, use LDPC transmission rates
*/
#define TX_RATE_SETTING_1_LDPC_OFFSET                                0x00000004
#define TX_RATE_SETTING_1_LDPC_LSB                                   23
#define TX_RATE_SETTING_1_LDPC_MASK                                  0x00800000

/* Description		TX_RATE_SETTING_1_SGI
			
			Field only valid when pkt type is HT or VHT.
			
			When set, use short Guard interval transmission.
*/
#define TX_RATE_SETTING_1_SGI_OFFSET                                 0x00000004
#define TX_RATE_SETTING_1_SGI_LSB                                    24
#define TX_RATE_SETTING_1_SGI_MASK                                   0x01000000

/* Description		TX_RATE_SETTING_1_TX_PWR_SEC80
			
			Transmit Power (signed value) in units of 0.5 dBm for
			second segment. Used to control tx power of sec80 channel in
			80+80. Should be set to same value as tx_pwr for all other
			modes. <legal all>
*/
#define TX_RATE_SETTING_1_TX_PWR_SEC80_OFFSET                        0x00000004
#define TX_RATE_SETTING_1_TX_PWR_SEC80_LSB                           25
#define TX_RATE_SETTING_1_TX_PWR_SEC80_MASK                          0xfe000000


#endif // _TX_RATE_SETTING_H_