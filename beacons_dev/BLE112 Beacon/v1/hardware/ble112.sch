<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ble112">
<description>Generated from &lt;b&gt;BLE112 Breakout Board v1.1.sch&lt;/b&gt;&lt;p&gt;
by exp-project-lbr.ulp</description>
<packages>
<package name="SF-BLUEGIGA_BLE112-A">
<description>Bluetooth Low Energy single-mode module - Bluetooth 4.0, chip antenna</description>
<wire x1="-6.05" y1="-9.05" x2="-6.05" y2="9.05" width="0.127" layer="21"/>
<wire x1="-6.05" y1="9.05" x2="6" y2="9.05" width="0.127" layer="21"/>
<wire x1="6" y1="9.05" x2="6" y2="-9.05" width="0.127" layer="21"/>
<wire x1="6" y1="-9.05" x2="-6.05" y2="-9.05" width="0.127" layer="21"/>
<smd name="AVDD1" x="-6.05" y="6.9" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="AVDD2" x="-6.05" y="5.65" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="DVDD" x="3.1" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="GND1" x="-6.05" y="8.15" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="GND2" x="-6.05" y="-3.1" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="GND3" x="4.35" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="GND4" x="6" y="3.15" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_0" x="6" y="0.65" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_1" x="6" y="-0.6" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_2" x="6" y="-1.85" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_3" x="6" y="-3.1" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_4" x="6" y="-4.35" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_5" x="6" y="-5.6" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_6" x="6" y="-6.85" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P0_7" x="1.85" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_0" x="0.6" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_1" x="-0.65" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_2" x="-1.9" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_3" x="-3.15" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_4" x="-4.4" y="-9.05" dx="0.85" dy="3" layer="1" roundness="100" rot="R180"/>
<smd name="P1_5" x="-6.05" y="-6.85" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P1_6" x="-6.05" y="-0.6" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P1_7" x="-6.05" y="0.65" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P2_0" x="-6.05" y="1.9" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P2_1" x="-6.05" y="3.15" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="P2_2" x="-6.05" y="4.4" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="RESET" x="6" y="1.9" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="USB+" x="-6.05" y="-4.35" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="USB-" x="-6.05" y="-5.6" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<smd name="VDD_USB" x="-6.05" y="-1.85" dx="0.85" dy="3" layer="1" roundness="100" rot="R90"/>
<text x="-4.35" y="7.8" size="0.8128" layer="21" rot="SR0">1</text>
<text x="-4.35" y="-7.25" size="0.8128" layer="21" rot="SR0">13</text>
<text x="3" y="-7.25" size="0.8128" layer="21" rot="SR0">22</text>
<text x="3" y="2.75" size="0.8128" layer="21" rot="SR0">30</text>
<text x="-6" y="9.4" size="1.016" layer="25" rot="SR0">&gt;NAME</text>
<text x="0" y="9.4" size="1.016" layer="27" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="SF-BLUEGIGA_BLE112-A-VISUAL">
<wire x1="-15.24" y1="22.86" x2="15.24" y2="22.86" width="0.254" layer="94"/>
<wire x1="15.24" y1="22.86" x2="15.24" y2="-22.86" width="0.254" layer="94"/>
<wire x1="15.24" y1="-22.86" x2="-15.24" y2="-22.86" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-22.86" x2="-15.24" y2="22.86" width="0.254" layer="94"/>
<pin name="AVDD" x="-20.32" y="17.78" visible="pin" length="middle" direction="pwr"/>
<pin name="AVDD@2" x="-20.32" y="15.24" visible="pin" length="middle" direction="pwr"/>
<pin name="DVDD" x="7.62" y="-27.94" visible="pin" length="middle" direction="pwr" rot="R90"/>
<pin name="GND" x="-20.32" y="20.32" visible="pin" length="middle" direction="pwr"/>
<pin name="GND@2" x="-20.32" y="-2.54" visible="pin" length="middle" direction="pwr"/>
<pin name="GND@3" x="10.16" y="-27.94" visible="pin" length="middle" direction="pwr" rot="R90"/>
<pin name="GND@4" x="20.32" y="10.16" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="P0_0" x="20.32" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="P0_1" x="20.32" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="P0_2" x="20.32" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="P0_3" x="20.32" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="P0_4" x="20.32" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="P0_5" x="20.32" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="P0_6" x="20.32" y="-10.16" visible="pin" length="middle" rot="R180"/>
<pin name="P0_7" x="5.08" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_0" x="2.54" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_1" x="0" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_2" x="-2.54" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_3" x="-5.08" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_4" x="-7.62" y="-27.94" visible="pin" length="middle" rot="R90"/>
<pin name="P1_5" x="-20.32" y="-10.16" visible="pin" length="middle"/>
<pin name="P1_6" x="-20.32" y="2.54" visible="pin" length="middle"/>
<pin name="P1_7" x="-20.32" y="5.08" visible="pin" length="middle"/>
<pin name="P2_0" x="-20.32" y="7.62" visible="pin" length="middle"/>
<pin name="P2_1" x="-20.32" y="10.16" visible="pin" length="middle"/>
<pin name="P2_2" x="-20.32" y="12.7" visible="pin" length="middle"/>
<pin name="RESET" x="20.32" y="7.62" visible="pin" length="middle" direction="in" rot="R180"/>
<pin name="USB+" x="-20.32" y="-5.08" visible="pin" length="middle"/>
<pin name="USB-" x="-20.32" y="-7.62" visible="pin" length="middle"/>
<pin name="VDD_USB" x="-20.32" y="0" visible="pin" length="middle" direction="pwr"/>
<text x="1.778" y="24.13" size="2.54" layer="96">&gt;VALUE</text>
<text x="-15.24" y="24.13" size="2.54" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="SF-BLUEGIGA_BLE112-A-VISUAL" prefix="U">
<description>Bluetooth Low Energy single-mode module - Bluetooth 4.0, chip antenna</description>
<gates>
<gate name="G$1" symbol="SF-BLUEGIGA_BLE112-A-VISUAL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SF-BLUEGIGA_BLE112-A">
<connects>
<connect gate="G$1" pin="AVDD" pad="AVDD1"/>
<connect gate="G$1" pin="AVDD@2" pad="AVDD2"/>
<connect gate="G$1" pin="DVDD" pad="DVDD"/>
<connect gate="G$1" pin="GND" pad="GND1"/>
<connect gate="G$1" pin="GND@2" pad="GND2"/>
<connect gate="G$1" pin="GND@3" pad="GND3"/>
<connect gate="G$1" pin="GND@4" pad="GND4"/>
<connect gate="G$1" pin="P0_0" pad="P0_0"/>
<connect gate="G$1" pin="P0_1" pad="P0_1"/>
<connect gate="G$1" pin="P0_2" pad="P0_2"/>
<connect gate="G$1" pin="P0_3" pad="P0_3"/>
<connect gate="G$1" pin="P0_4" pad="P0_4"/>
<connect gate="G$1" pin="P0_5" pad="P0_5"/>
<connect gate="G$1" pin="P0_6" pad="P0_6"/>
<connect gate="G$1" pin="P0_7" pad="P0_7"/>
<connect gate="G$1" pin="P1_0" pad="P1_0"/>
<connect gate="G$1" pin="P1_1" pad="P1_1"/>
<connect gate="G$1" pin="P1_2" pad="P1_2"/>
<connect gate="G$1" pin="P1_3" pad="P1_3"/>
<connect gate="G$1" pin="P1_4" pad="P1_4"/>
<connect gate="G$1" pin="P1_5" pad="P1_5"/>
<connect gate="G$1" pin="P1_6" pad="P1_6"/>
<connect gate="G$1" pin="P1_7" pad="P1_7"/>
<connect gate="G$1" pin="P2_0" pad="P2_0"/>
<connect gate="G$1" pin="P2_1" pad="P2_1"/>
<connect gate="G$1" pin="P2_2" pad="P2_2"/>
<connect gate="G$1" pin="RESET" pad="RESET"/>
<connect gate="G$1" pin="USB+" pad="USB+"/>
<connect gate="G$1" pin="USB-" pad="USB-"/>
<connect gate="G$1" pin="VDD_USB" pad="VDD_USB"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="keystone_106">
<packages>
<package name="CELL_HOLDER_PACKAGE">
<circle x="0" y="0" radius="13.8811" width="0.127" layer="21"/>
<pad name="VDD" x="-5.2832" y="0" drill="1.524" diameter="5.08"/>
<pad name="VPP" x="15.2146" y="0" drill="1.524" diameter="5.08"/>
<circle x="0" y="0" radius="10.1092" width="0.127" layer="21"/>
<circle x="0" y="0" radius="9.525" width="0.127" layer="21"/>
<wire x1="13.716" y1="2.54" x2="17.78" y2="2.54" width="0.127" layer="21"/>
<wire x1="13.716" y1="-2.54" x2="17.78" y2="-2.54" width="0.127" layer="21"/>
<wire x1="17.78" y1="2.54" x2="17.78" y2="-2.54" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="KEYSTONE_106">
<pin name="VPP" x="-66.04" y="2.54" length="middle"/>
<pin name="VDD" x="-27.94" y="2.54" length="middle" rot="R180"/>
<text x="-50.8" y="15.24" size="1.778" layer="95">&gt;NAME</text>
<text x="-50.8" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<wire x1="-53.34" y1="15.24" x2="-53.34" y2="2.54" width="0.254" layer="94"/>
<wire x1="-53.34" y1="2.54" x2="-53.34" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-45.72" y1="7.62" x2="-45.72" y2="2.54" width="0.254" layer="94"/>
<wire x1="-45.72" y1="2.54" x2="-45.72" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-60.96" y1="2.54" x2="-53.34" y2="2.54" width="0.254" layer="94"/>
<wire x1="-33.02" y1="2.54" x2="-45.72" y2="2.54" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="KEYSTON_106">
<description>Support de pile Keystone 106 pour CR2032</description>
<gates>
<gate name="G$1" symbol="KEYSTONE_106" x="-35.56" y="-2.54"/>
</gates>
<devices>
<device name="" package="CELL_HOLDER_PACKAGE">
<connects>
<connect gate="G$1" pin="VDD" pad="VDD"/>
<connect gate="G$1" pin="VPP" pad="VPP"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2X05">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-6.35" y1="-1.905" x2="-5.715" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="2.54" x2="-4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="0.635" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.27" y2="1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.905" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.905" y1="2.54" x2="3.175" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.175" y1="2.54" x2="3.81" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="3.175" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="0.635" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-1.905" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="4.445" y2="-2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.905" x2="4.445" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.445" y1="2.54" x2="5.715" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.715" y1="2.54" x2="6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="5.715" y2="-2.54" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="2" x="-5.08" y="1.27" drill="1.016" shape="octagon"/>
<pad name="3" x="-2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="4" x="-2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="5" x="0" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="6" x="0" y="1.27" drill="1.016" shape="octagon"/>
<pad name="7" x="2.54" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="8" x="2.54" y="1.27" drill="1.016" shape="octagon"/>
<pad name="9" x="5.08" y="-1.27" drill="1.016" shape="octagon"/>
<pad name="10" x="5.08" y="1.27" drill="1.016" shape="octagon"/>
<text x="-6.35" y="3.175" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.35" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.016" layer="51"/>
<rectangle x1="-5.334" y1="1.016" x2="-4.826" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="1.016" x2="-2.286" y2="1.524" layer="51"/>
<rectangle x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.016" layer="51"/>
<rectangle x1="-0.254" y1="1.016" x2="0.254" y2="1.524" layer="51"/>
<rectangle x1="-0.254" y1="-1.524" x2="0.254" y2="-1.016" layer="51"/>
<rectangle x1="2.286" y1="1.016" x2="2.794" y2="1.524" layer="51"/>
<rectangle x1="2.286" y1="-1.524" x2="2.794" y2="-1.016" layer="51"/>
<rectangle x1="4.826" y1="1.016" x2="5.334" y2="1.524" layer="51"/>
<rectangle x1="4.826" y1="-1.524" x2="5.334" y2="-1.016" layer="51"/>
</package>
<package name="2X05/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-6.35" y1="-1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="6.985" x2="-5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="6.985" x2="5.08" y2="1.27" width="0.762" layer="21"/>
<pad name="2" x="-5.08" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="4" x="-2.54" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="6" x="0" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="8" x="2.54" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="10" x="5.08" y="-3.81" drill="1.016" shape="octagon"/>
<pad name="1" x="-5.08" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="3" x="-2.54" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="5" x="0" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="7" x="2.54" y="-6.35" drill="1.016" shape="octagon"/>
<pad name="9" x="5.08" y="-6.35" drill="1.016" shape="octagon"/>
<text x="-6.985" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="8.255" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-5.461" y1="0.635" x2="-4.699" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="4.699" y1="0.635" x2="5.461" y2="1.143" layer="21"/>
<rectangle x1="-5.461" y1="-2.921" x2="-4.699" y2="-1.905" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-5.461" y1="-5.461" x2="-4.699" y2="-4.699" layer="21"/>
<rectangle x1="-5.461" y1="-4.699" x2="-4.699" y2="-2.921" layer="51"/>
<rectangle x1="-2.921" y1="-4.699" x2="-2.159" y2="-2.921" layer="51"/>
<rectangle x1="-2.921" y1="-5.461" x2="-2.159" y2="-4.699" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-5.461" x2="0.381" y2="-4.699" layer="21"/>
<rectangle x1="-0.381" y1="-4.699" x2="0.381" y2="-2.921" layer="51"/>
<rectangle x1="2.159" y1="-4.699" x2="2.921" y2="-2.921" layer="51"/>
<rectangle x1="2.159" y1="-5.461" x2="2.921" y2="-4.699" layer="21"/>
<rectangle x1="4.699" y1="-2.921" x2="5.461" y2="-1.905" layer="21"/>
<rectangle x1="4.699" y1="-5.461" x2="5.461" y2="-4.699" layer="21"/>
<rectangle x1="4.699" y1="-4.699" x2="5.461" y2="-2.921" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="PINH2X5">
<wire x1="-6.35" y1="-7.62" x2="8.89" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="8.89" y1="-7.62" x2="8.89" y2="7.62" width="0.4064" layer="94"/>
<wire x1="8.89" y1="7.62" x2="-6.35" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="7.62" x2="-6.35" y2="-7.62" width="0.4064" layer="94"/>
<text x="-6.35" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="5.08" y="5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="3" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="5.08" y="2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="5" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="5.08" y="0" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="7" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="8" x="5.08" y="-2.54" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
<pin name="9" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="10" x="5.08" y="-5.08" visible="pad" length="short" direction="pas" function="dot" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-2X5" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINH2X5" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2X05">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="2X05/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="@Club_passif">
<description>&lt;b&gt;Librairie RCL et passif du club robot&lt;/b&gt;&lt;p&gt;

&lt;li&gt; &lt;i&gt; - Résistances
&lt;li&gt; &lt;i&gt; - Capacités
&lt;li&gt; &lt;i&gt; - LEDs
&lt;li&gt;
&lt;li&gt;
&lt;author&gt;Created by fabien&lt;/author&gt;</description>
<packages>
<package name="E2,5-6">
<description>&lt;b&gt;ELECTROLYTIC CAPACITOR&lt;/b&gt;&lt;p&gt;
grid 2.54 mm, diameter 6 mm</description>
<wire x1="-2.032" y1="1.27" x2="-1.651" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="0.889" x2="-1.651" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="1.27" x2="-1.27" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="1.27" x2="-1.651" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="0" x2="-0.762" y2="0" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-1.27" x2="-0.254" y2="1.27" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="1.27" x2="-0.762" y2="1.27" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="1.27" x2="-0.762" y2="0" width="0.1524" layer="51"/>
<wire x1="0.635" y1="0" x2="1.651" y2="0" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="2.794" width="0.1524" layer="21"/>
<pad name="-" x="1.27" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="+" x="-1.27" y="0" drill="0.4064" diameter="1.9304"/>
<text x="2.667" y="1.524" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="2.667" y="-2.667" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="0.254" y1="-1.27" x2="0.762" y2="1.27" layer="51"/>
</package>
<package name="E2,5-7">
<description>&lt;b&gt;ELECTROLYTIC CAPACITOR&lt;/b&gt;&lt;p&gt;
grid 2.54 mm, diameter 7 mm</description>
<wire x1="-3.048" y1="0" x2="-2.286" y2="0" width="0.1524" layer="21"/>
<wire x1="-2.667" y1="-0.381" x2="-2.667" y2="0.381" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="0" x2="-0.762" y2="0" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-1.27" x2="-0.254" y2="1.27" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="1.27" x2="-0.762" y2="1.27" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="1.27" x2="-0.762" y2="0" width="0.1524" layer="51"/>
<wire x1="0.635" y1="0" x2="1.651" y2="0" width="0.1524" layer="51"/>
<pad name="-" x="1.27" y="0" drill="0.8128" diameter="1.6002" shape="octagon"/>
<pad name="+" x="-1.27" y="0" drill="0.8128" diameter="1.6002"/>
<text x="3.048" y="2.032" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.048" y="-3.175" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="0.254" y1="-1.27" x2="0.762" y2="1.27" layer="51"/>
<wire x1="5" y1="0" x2="-5" y2="0" width="0.127" layer="21"/>
<wire x1="-5" y1="0" x2="-5" y2="28" width="0.127" layer="21"/>
<wire x1="-5" y1="28" x2="5" y2="28" width="0.127" layer="21"/>
<wire x1="5" y1="28" x2="5" y2="0" width="0.127" layer="21"/>
<dimension x1="-5" y1="0" x2="-5" y2="28" x3="-11" y3="14" textsize="1.27" layer="21"/>
<dimension x1="-5" y1="28" x2="5" y2="28" x3="0" y3="32" textsize="1.27" layer="21"/>
</package>
<package name="1206">
<description>&lt;b&gt;CMS 1206&lt;/b&gt;&lt;p&gt;
pour résistances, capas, leds...</description>
<wire x1="1.55" y1="-0.75" x2="-1.55" y2="-0.75" width="0.1016" layer="51"/>
<wire x1="-1.55" y1="-0.75" x2="-1.55" y2="0.75" width="0.1016" layer="51"/>
<wire x1="-1.55" y1="0.75" x2="1.55" y2="0.75" width="0.1016" layer="51"/>
<wire x1="1.55" y1="0.75" x2="1.55" y2="-0.75" width="0.1016" layer="51"/>
<wire x1="-0.55" y1="-0.5" x2="0.55" y2="-0.5" width="0.1016" layer="21" curve="95.452622" cap="flat"/>
<wire x1="-0.55" y1="-0.5" x2="-0.55" y2="0.5" width="0.1016" layer="51" curve="-84.547378" cap="flat"/>
<wire x1="-0.55" y1="0.5" x2="0.55" y2="0.5" width="0.1016" layer="21" curve="-95.452622" cap="flat"/>
<wire x1="0.55" y1="0.5" x2="0.55" y2="-0.5" width="0.1016" layer="51" curve="-84.547378" cap="flat"/>
<smd name="A" x="-1.422" y="0" dx="1.6" dy="1.803" layer="1"/>
<smd name="C" x="1.422" y="0" dx="1.6" dy="1.803" layer="1"/>
<text x="-1.27" y="1.27" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.27" y="-2.54" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.1" y1="-0.1" x2="0.1" y2="0.1" layer="21"/>
<rectangle x1="0.45" y1="-0.7" x2="0.8" y2="-0.45" layer="51"/>
<rectangle x1="0.8" y1="-0.7" x2="0.9" y2="0.5" layer="51"/>
<rectangle x1="0.8" y1="0.55" x2="0.9" y2="0.7" layer="51"/>
<rectangle x1="-0.9" y1="-0.7" x2="-0.8" y2="0.5" layer="51"/>
<rectangle x1="-0.9" y1="0.55" x2="-0.8" y2="0.7" layer="51"/>
<rectangle x1="0.45" y1="-0.7" x2="0.6" y2="-0.45" layer="21"/>
</package>
<package name="LED3MM">
<description>&lt;B&gt;LED 3mm&lt;/B&gt;&lt;p&gt;
pastille octogonale = méplat</description>
<wire x1="1.5748" y1="-1.27" x2="1.5748" y2="1.27" width="0.254" layer="51"/>
<wire x1="-1.524" y1="0" x2="-1.1708" y2="0.9756" width="0.1524" layer="51" curve="-39.80361" cap="flat"/>
<wire x1="-1.524" y1="0" x2="-1.1391" y2="-1.0125" width="0.1524" layer="51" curve="41.633208" cap="flat"/>
<wire x1="1.1571" y1="0.9918" x2="1.524" y2="0" width="0.1524" layer="51" curve="-40.601165" cap="flat"/>
<wire x1="1.1708" y1="-0.9756" x2="1.524" y2="0" width="0.1524" layer="51" curve="39.80361" cap="flat"/>
<wire x1="0" y1="1.524" x2="1.2401" y2="0.8858" width="0.1524" layer="21" curve="-54.461337" cap="flat"/>
<wire x1="-1.2192" y1="0.9144" x2="0" y2="1.524" width="0.1524" layer="21" curve="-53.130102" cap="flat"/>
<wire x1="0" y1="-1.524" x2="1.203" y2="-0.9356" width="0.1524" layer="21" curve="52.126876" cap="flat"/>
<wire x1="-1.203" y1="-0.9356" x2="0" y2="-1.524" width="0.1524" layer="21" curve="52.126876" cap="flat"/>
<wire x1="-0.635" y1="0" x2="0" y2="0.635" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="-1.016" y1="0" x2="0" y2="1.016" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-0.635" x2="0.635" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="-1.016" x2="1.016" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.032" x2="1.561" y2="1.3009" width="0.254" layer="21" curve="-50.193108" cap="flat"/>
<wire x1="-1.7929" y1="0.9562" x2="0" y2="2.032" width="0.254" layer="21" curve="-61.926949" cap="flat"/>
<wire x1="0" y1="-2.032" x2="1.5512" y2="-1.3126" width="0.254" layer="21" curve="49.763022" cap="flat"/>
<wire x1="-1.7643" y1="-1.0082" x2="0" y2="-2.032" width="0.254" layer="21" curve="60.255215" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7891" y2="0.9634" width="0.254" layer="51" curve="-28.301701" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7306" y2="-1.065" width="0.254" layer="51" curve="31.60822" cap="flat"/>
<pad name="A" x="-1.27" y="0" drill="0.4064" diameter="1.9304"/>
<pad name="K" x="1.27" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="1.905" y="0.381" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="1.905" y="-1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="LED5MM">
<description>&lt;B&gt;LED 5mm&lt;/B&gt;&lt;p&gt;
pastille octogonale = méplat</description>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.254" layer="21" curve="-286.260205" cap="flat"/>
<wire x1="-1.143" y1="0" x2="0" y2="1.143" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.143" x2="1.143" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-1.651" y1="0" x2="0" y2="1.651" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.651" x2="1.651" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-2.159" y1="0" x2="0" y2="2.159" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-2.159" x2="2.159" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<circle x="0" y="0" radius="2.54" width="0.1524" layer="21"/>
<pad name="A" x="-1.27" y="0" drill="0.8128" diameter="1.9304"/>
<pad name="K" x="1.27" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="3.175" y="0.5334" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.2004" y="-1.8034" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="0207/10">
<description>&lt;b&gt;Implantation horizontale 4 pas&lt;/b&gt;&lt;p&gt;
pour résistances 1/4W&lt;p&gt;grid 10 mm</description>
<wire x1="5.08" y1="0" x2="4.064" y2="0" width="0.6096" layer="51"/>
<wire x1="-5.08" y1="0" x2="-4.064" y2="0" width="0.6096" layer="51"/>
<wire x1="-3.175" y1="0.889" x2="-2.921" y2="1.143" width="0.1524" layer="21" curve="-90"/>
<wire x1="-3.175" y1="-0.889" x2="-2.921" y2="-1.143" width="0.1524" layer="21" curve="90"/>
<wire x1="2.921" y1="-1.143" x2="3.175" y2="-0.889" width="0.1524" layer="21" curve="90"/>
<wire x1="2.921" y1="1.143" x2="3.175" y2="0.889" width="0.1524" layer="21" curve="-90"/>
<wire x1="-3.175" y1="-0.889" x2="-3.175" y2="0.889" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="1.143" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="1.016" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="-1.143" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="-1.016" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="-2.413" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="-2.413" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.143" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.921" y1="-1.143" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-0.889" x2="3.175" y2="0.889" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="2" x="5.08" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="-3.048" y="1.524" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.2606" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="3.175" y1="-0.3048" x2="4.0386" y2="0.3048" layer="21"/>
<rectangle x1="-4.0386" y1="-0.3048" x2="-3.175" y2="0.3048" layer="21"/>
</package>
<package name="0207/7">
<description>&lt;b&gt;Implantation horizontale 3 pas&lt;/b&gt;&lt;p&gt;
pour résistances 1/4W&lt;p&gt;grid 7.5 mm</description>
<wire x1="-3.81" y1="0" x2="-3.429" y2="0" width="0.6096" layer="51"/>
<wire x1="-3.175" y1="0.889" x2="-2.921" y2="1.143" width="0.1524" layer="21" curve="-90" cap="flat"/>
<wire x1="-3.175" y1="-0.889" x2="-2.921" y2="-1.143" width="0.1524" layer="21" curve="90" cap="flat"/>
<wire x1="2.921" y1="-1.143" x2="3.175" y2="-0.889" width="0.1524" layer="21" curve="90" cap="flat"/>
<wire x1="2.921" y1="1.143" x2="3.175" y2="0.889" width="0.1524" layer="21" curve="-90" cap="flat"/>
<wire x1="-3.175" y1="-0.889" x2="-3.175" y2="0.889" width="0.1524" layer="51"/>
<wire x1="-2.921" y1="1.143" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="1.016" x2="-2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="-1.143" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="-1.016" x2="-2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="-2.413" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="2.413" y1="-1.016" x2="-2.413" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.143" x2="2.54" y2="1.143" width="0.1524" layer="21"/>
<wire x1="2.921" y1="-1.143" x2="2.54" y2="-1.143" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-0.889" x2="3.175" y2="0.889" width="0.1524" layer="51"/>
<wire x1="3.429" y1="0" x2="3.81" y2="0" width="0.6096" layer="51"/>
<pad name="1" x="-3.81" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="2" x="3.81" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="-2.54" y="1.397" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.286" y="-0.5588" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-3.429" y1="-0.3048" x2="-3.175" y2="0.3048" layer="51"/>
<rectangle x1="3.175" y1="-0.3048" x2="3.429" y2="0.3048" layer="51"/>
</package>
<package name="0207/5V">
<description>&lt;b&gt;Implantation verticale 2 pas&lt;/b&gt;&lt;p&gt;
pour résistances &lt;p&gt;grid 5 mm</description>
<wire x1="-2.54" y1="0" x2="-0.889" y2="0" width="0.6096" layer="51"/>
<wire x1="-0.762" y1="0" x2="0.762" y2="0" width="0.6096" layer="21"/>
<wire x1="0.889" y1="0" x2="2.54" y2="0" width="0.6096" layer="51"/>
<circle x="-2.54" y="0" radius="1.27" width="0.1016" layer="21"/>
<circle x="-2.54" y="0" radius="1.016" width="0.1524" layer="51"/>
<pad name="1" x="-2.54" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="-1.143" y="0.889" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.143" y="-2.159" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="0207/2V">
<description>&lt;b&gt;Implantation verticale 1 pas&lt;/b&gt;&lt;p&gt;
pour résistances et diodes&lt;p&gt;grid 2.5 mm</description>
<wire x1="-1.27" y1="0" x2="-0.381" y2="0" width="0.6096" layer="51"/>
<wire x1="-0.254" y1="0" x2="0.254" y2="0" width="0.6096" layer="21"/>
<wire x1="0.381" y1="0" x2="1.27" y2="0" width="0.6096" layer="51"/>
<circle x="-1.27" y="0" radius="1.27" width="0.1524" layer="21"/>
<circle x="-1.27" y="0" radius="1.016" width="0.1524" layer="51"/>
<pad name="1" x="-1.27" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="2" x="1.27" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="-0.0508" y="1.016" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-0.0508" y="-2.2352" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="R0805">
<description>&lt;b&gt;CMS 0805&lt;/b&gt;&lt;p&gt;
pour résistances (attention délicat à souder)</description>
<wire x1="-0.41" y1="0.635" x2="0.41" y2="0.635" width="0.1524" layer="51"/>
<wire x1="-0.41" y1="-0.635" x2="0.41" y2="-0.635" width="0.1524" layer="51"/>
<wire x1="-1.973" y1="0.983" x2="1.973" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="0.983" x2="1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="-0.983" x2="-1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.973" y1="-0.983" x2="-1.973" y2="0.983" width="0.0508" layer="39"/>
<smd name="1" x="-0.85" y="0" dx="1.3" dy="1.5" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.3" dy="1.5" layer="1"/>
<text x="-0.762" y="1.016" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-2.286" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="0.4064" y1="-0.6985" x2="1.0564" y2="0.7015" layer="51"/>
<rectangle x1="-1.0668" y1="-0.6985" x2="-0.4168" y2="0.7015" layer="51"/>
<rectangle x1="-0.1999" y1="-0.5001" x2="0.1999" y2="0.5001" layer="35"/>
</package>
<package name="R1206">
<description>&lt;b&gt;CMS 1206&lt;/b&gt;&lt;p&gt;
pour résistances, capas, leds...</description>
<wire x1="0.9525" y1="-0.8128" x2="-0.9652" y2="-0.8128" width="0.1524" layer="51"/>
<wire x1="0.9525" y1="0.8128" x2="-0.9652" y2="0.8128" width="0.1524" layer="51"/>
<wire x1="-2.473" y1="0.983" x2="2.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="0.983" x2="2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="2.473" y1="-0.983" x2="-2.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-2.473" y1="-0.983" x2="-2.473" y2="0.983" width="0.0508" layer="39"/>
<smd name="2" x="1.422" y="0" dx="1.6" dy="1.803" layer="1"/>
<smd name="1" x="-1.422" y="0" dx="1.6" dy="1.803" layer="1"/>
<text x="-1.397" y="1.143" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.397" y="-2.413" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-1.6891" y1="-0.8763" x2="-0.9525" y2="0.8763" layer="51"/>
<rectangle x1="0.9525" y1="-0.8763" x2="1.6891" y2="0.8763" layer="51"/>
<rectangle x1="-0.3" y1="-0.7" x2="0.3" y2="0.7" layer="35"/>
</package>
</packages>
<symbols>
<symbol name="CPOL_">
<wire x1="-1.524" y1="0" x2="-1.524" y2="-0.889" width="0.254" layer="94"/>
<wire x1="-1.524" y1="0" x2="1.524" y2="0" width="0.254" layer="94"/>
<wire x1="-1.524" y1="-0.889" x2="1.524" y2="-0.889" width="0.254" layer="94"/>
<wire x1="1.524" y1="0" x2="1.524" y2="-0.889" width="0.254" layer="94"/>
<text x="-1.651" y="0.381" size="1.27" layer="94">+</text>
<text x="1.143" y="0.508" size="1.778" layer="95">&gt;NAME</text>
<text x="1.143" y="-4.572" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-1.651" y1="-2.54" x2="1.651" y2="-1.651" layer="94"/>
<pin name="P$1" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="P$2" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
</symbol>
<symbol name="LED_">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-2.032" y1="-0.762" x2="-3.429" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="-3.302" y2="-3.302" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="1.27" y2="-2.54" width="0.254" layer="94"/>
<text x="3.556" y="-4.572" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-4.572" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="A" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="C" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<polygon width="0.1524" layer="94">
<vertex x="-3.429" y="-2.159"/>
<vertex x="-3.048" y="-1.27"/>
<vertex x="-2.54" y="-1.778"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-3.302" y="-3.302"/>
<vertex x="-2.921" y="-2.413"/>
<vertex x="-2.413" y="-2.921"/>
</polygon>
</symbol>
<symbol name="R_">
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="-2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0.889" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<text x="-2.6988" y="1.5875" size="1.27" layer="95">&gt;NAME</text>
<text x="-2.6988" y="-2.8575" size="1.27" layer="96">&gt;VALUE</text>
<pin name="P$1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="P$2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CPOL_" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="CPOL_" x="0" y="0"/>
</gates>
<devices>
<device name="DIAM5MM" package="E2,5-6">
<connects>
<connect gate="G$1" pin="P$1" pad="+"/>
<connect gate="G$1" pin="P$2" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="E2,5-7">
<connects>
<connect gate="G$1" pin="P$1" pad="+"/>
<connect gate="G$1" pin="P$2" pad="-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="LED_" prefix="LED">
<description>LEDs, lumière quoi !   1.8V &lt; Vseuil &lt; 2.0V  environ</description>
<gates>
<gate name="G$1" symbol="LED_" x="0" y="0"/>
</gates>
<devices>
<device name="1206" package="1206">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3MM" package="LED3MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5MM" package="LED5MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="R_" prefix="R" uservalue="yes">
<description>Résistances standards</description>
<gates>
<gate name="G$1" symbol="R_" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="4PAS" package="0207/10">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3PAS" package="0207/7">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="2PAS_VERTI" package="0207/5V">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="1PAS_VERTI" package="0207/2V">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="0805" package="R0805">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="1206" package="R1206">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="1210" package="0207/10">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U1" library="ble112" deviceset="SF-BLUEGIGA_BLE112-A-VISUAL" device=""/>
<part name="U$1" library="keystone_106" deviceset="KEYSTON_106" device=""/>
<part name="JP1" library="pinhead" deviceset="PINHD-2X5" device=""/>
<part name="C1" library="@Club_passif" deviceset="CPOL_" device="DIAM5MM" value="100uF"/>
<part name="C2" library="@Club_passif" deviceset="CPOL_" device="" value="1uF"/>
<part name="C3" library="@Club_passif" deviceset="CPOL_" device="" value="1uF"/>
<part name="C4" library="@Club_passif" deviceset="CPOL_" device="" value="1uF"/>
<part name="LED1" library="@Club_passif" deviceset="LED_" device="3MM"/>
<part name="LED2" library="@Club_passif" deviceset="LED_" device="3MM"/>
<part name="R1" library="@Club_passif" deviceset="R_" device="4PAS" value="1000"/>
<part name="R2" library="@Club_passif" deviceset="R_" device="4PAS" value="1000"/>
</parts>
<sheets>
<sheet>
<plain>
<text x="-38.1" y="88.9" size="2.54" layer="97" font="vector">Alimentation</text>
<text x="33.02" y="88.9" size="2.54" layer="97" font="vector">BLE112</text>
<text x="165.1" y="88.9" size="2.54" layer="97">Prog</text>
<text x="165.1" y="27.94" size="2.54" layer="97">Debug</text>
</plain>
<instances>
<instance part="U1" gate="G$1" x="106.68" y="129.54"/>
<instance part="U$1" gate="G$1" x="-27.94" y="83.82" rot="R270"/>
<instance part="JP1" gate="A" x="187.96" y="132.08"/>
<instance part="C1" gate="G$1" x="0" y="134.62"/>
<instance part="C2" gate="G$1" x="55.88" y="139.7"/>
<instance part="C3" gate="G$1" x="71.12" y="124.46"/>
<instance part="C4" gate="G$1" x="114.3" y="93.98"/>
<instance part="LED1" gate="G$1" x="170.18" y="68.58"/>
<instance part="LED2" gate="G$1" x="193.04" y="68.58"/>
<instance part="R1" gate="G$1" x="193.04" y="55.88" rot="R90"/>
<instance part="R2" gate="G$1" x="170.18" y="55.88" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<wire x1="-43.18" y1="165.1" x2="25.4" y2="165.1" width="0.1524" layer="91"/>
<wire x1="25.4" y1="165.1" x2="25.4" y2="83.82" width="0.1524" layer="91"/>
<wire x1="25.4" y1="83.82" x2="-43.18" y2="83.82" width="0.1524" layer="91"/>
<wire x1="-43.18" y1="83.82" x2="-43.18" y2="165.1" width="0.1524" layer="91"/>
<wire x1="25.4" y1="165.1" x2="160.02" y2="165.1" width="0.1524" layer="91"/>
<wire x1="160.02" y1="165.1" x2="160.02" y2="83.82" width="0.1524" layer="91"/>
<wire x1="160.02" y1="83.82" x2="25.4" y2="83.82" width="0.1524" layer="91"/>
<wire x1="160.02" y1="165.1" x2="215.9" y2="165.1" width="0.1524" layer="91"/>
<wire x1="215.9" y1="165.1" x2="215.9" y2="83.82" width="0.1524" layer="91"/>
<wire x1="215.9" y1="83.82" x2="160.02" y2="83.82" width="0.1524" layer="91"/>
<wire x1="160.02" y1="83.82" x2="160.02" y2="25.4" width="0.1524" layer="91"/>
<wire x1="160.02" y1="25.4" x2="215.9" y2="25.4" width="0.1524" layer="91"/>
<wire x1="215.9" y1="25.4" x2="215.9" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="3V" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VPP"/>
<wire x1="-25.4" y1="149.86" x2="0" y2="149.86" width="0.1524" layer="91"/>
<wire x1="0" y1="149.86" x2="0" y2="137.16" width="0.1524" layer="91"/>
<wire x1="0" y1="149.86" x2="10.16" y2="149.86" width="0.1524" layer="91"/>
<junction x="0" y="149.86"/>
<label x="12.7" y="149.86" size="1.778" layer="95"/>
<pinref part="C1" gate="G$1" pin="P$1"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="DVDD"/>
<wire x1="114.3" y1="96.52" x2="114.3" y2="99.06" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="VDD_USB"/>
<wire x1="114.3" y1="99.06" x2="114.3" y2="101.6" width="0.1524" layer="91"/>
<wire x1="86.36" y1="129.54" x2="71.12" y2="129.54" width="0.1524" layer="91"/>
<wire x1="71.12" y1="129.54" x2="63.5" y2="129.54" width="0.1524" layer="91"/>
<wire x1="114.3" y1="99.06" x2="63.5" y2="99.06" width="0.1524" layer="91"/>
<wire x1="63.5" y1="99.06" x2="63.5" y2="129.54" width="0.1524" layer="91"/>
<junction x="114.3" y="99.06"/>
<junction x="63.5" y="129.54"/>
<pinref part="U1" gate="G$1" pin="AVDD"/>
<wire x1="86.36" y1="147.32" x2="83.82" y2="147.32" width="0.1524" layer="91"/>
<wire x1="83.82" y1="147.32" x2="83.82" y2="144.78" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="AVDD@2"/>
<wire x1="83.82" y1="144.78" x2="86.36" y2="144.78" width="0.1524" layer="91"/>
<wire x1="83.82" y1="147.32" x2="63.5" y2="147.32" width="0.1524" layer="91"/>
<junction x="83.82" y="147.32"/>
<wire x1="63.5" y1="129.54" x2="63.5" y2="147.32" width="0.1524" layer="91"/>
<wire x1="63.5" y1="147.32" x2="55.88" y2="147.32" width="0.1524" layer="91"/>
<junction x="63.5" y="147.32"/>
<wire x1="55.88" y1="147.32" x2="43.18" y2="147.32" width="0.1524" layer="91"/>
<wire x1="55.88" y1="142.24" x2="55.88" y2="147.32" width="0.1524" layer="91"/>
<junction x="55.88" y="147.32"/>
<label x="43.18" y="147.32" size="1.778" layer="95"/>
<pinref part="C2" gate="G$1" pin="P$1"/>
<pinref part="C4" gate="G$1" pin="P$1"/>
<pinref part="C3" gate="G$1" pin="P$1"/>
<wire x1="71.12" y1="127" x2="71.12" y2="129.54" width="0.1524" layer="91"/>
<junction x="71.12" y="129.54"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="193.04" y1="137.16" x2="200.66" y2="137.16" width="0.1524" layer="91"/>
<label x="200.66" y="137.16" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VDD"/>
<wire x1="-25.4" y1="111.76" x2="0" y2="111.76" width="0.1524" layer="91"/>
<wire x1="0" y1="111.76" x2="10.16" y2="111.76" width="0.1524" layer="91"/>
<wire x1="0" y1="129.54" x2="0" y2="111.76" width="0.1524" layer="91"/>
<junction x="0" y="111.76"/>
<label x="12.7" y="111.76" size="1.778" layer="95"/>
<pinref part="C1" gate="G$1" pin="P$2"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND@4"/>
<wire x1="127" y1="139.7" x2="132.08" y2="139.7" width="0.1524" layer="91"/>
<label x="132.08" y="139.7" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="71.12" y1="119.38" x2="81.28" y2="119.38" width="0.1524" layer="91"/>
<wire x1="81.28" y1="119.38" x2="81.28" y2="127" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="GND@2"/>
<wire x1="81.28" y1="127" x2="86.36" y2="127" width="0.1524" layer="91"/>
<wire x1="81.28" y1="119.38" x2="81.28" y2="114.3" width="0.1524" layer="91"/>
<junction x="81.28" y="119.38"/>
<label x="81.28" y="111.76" size="1.778" layer="95"/>
<pinref part="C3" gate="G$1" pin="P$2"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="86.36" y1="149.86" x2="81.28" y2="149.86" width="0.1524" layer="91"/>
<label x="81.28" y="152.4" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="55.88" y1="134.62" x2="55.88" y2="121.92" width="0.1524" layer="91"/>
<label x="55.88" y="119.38" size="1.778" layer="95"/>
<pinref part="C2" gate="G$1" pin="P$2"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND@3"/>
<wire x1="116.84" y1="101.6" x2="121.92" y2="101.6" width="0.1524" layer="91"/>
<wire x1="121.92" y1="101.6" x2="121.92" y2="86.36" width="0.1524" layer="91"/>
<wire x1="121.92" y1="86.36" x2="114.3" y2="86.36" width="0.1524" layer="91"/>
<wire x1="114.3" y1="86.36" x2="114.3" y2="88.9" width="0.1524" layer="91"/>
<wire x1="114.3" y1="86.36" x2="106.68" y2="86.36" width="0.1524" layer="91"/>
<junction x="114.3" y="86.36"/>
<label x="101.6" y="88.9" size="1.778" layer="95"/>
<pinref part="C4" gate="G$1" pin="P$2"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="185.42" y1="137.16" x2="177.8" y2="137.16" width="0.1524" layer="91"/>
<label x="172.72" y="137.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R2" gate="G$1" pin="P$1"/>
<wire x1="170.18" y1="50.8" x2="170.18" y2="45.72" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="P$1"/>
<wire x1="193.04" y1="50.8" x2="193.04" y2="45.72" width="0.1524" layer="91"/>
<wire x1="193.04" y1="45.72" x2="182.88" y2="45.72" width="0.1524" layer="91"/>
<wire x1="182.88" y1="45.72" x2="170.18" y2="45.72" width="0.1524" layer="91"/>
<wire x1="182.88" y1="45.72" x2="182.88" y2="40.64" width="0.1524" layer="91"/>
<junction x="182.88" y="45.72"/>
<label x="185.42" y="40.64" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="185.42" y1="132.08" x2="177.8" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="JP1" gate="A" pin="9"/>
<wire x1="185.42" y1="127" x2="177.8" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="JP1" gate="A" pin="6"/>
<wire x1="193.04" y1="132.08" x2="200.66" y2="132.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="JP1" gate="A" pin="8"/>
<wire x1="193.04" y1="129.54" x2="200.66" y2="129.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="JP1" gate="A" pin="10"/>
<wire x1="193.04" y1="127" x2="200.66" y2="127" width="0.1524" layer="91"/>
</segment>
</net>
<net name="P2_2" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="P2_2"/>
<wire x1="86.36" y1="142.24" x2="81.28" y2="142.24" width="0.1524" layer="91"/>
<label x="76.2" y="142.24" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="185.42" y1="134.62" x2="177.8" y2="134.62" width="0.1524" layer="91"/>
<label x="172.72" y="134.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="P2_1" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="P2_1"/>
<wire x1="86.36" y1="139.7" x2="81.28" y2="139.7" width="0.1524" layer="91"/>
<label x="76.2" y="139.7" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="4"/>
<wire x1="193.04" y1="134.62" x2="200.66" y2="134.62" width="0.1524" layer="91"/>
<label x="200.66" y="134.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="RESET_N" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="RESET"/>
<wire x1="127" y1="137.16" x2="132.08" y2="137.16" width="0.1524" layer="91"/>
<label x="132.08" y="137.16" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="7"/>
<wire x1="185.42" y1="129.54" x2="177.8" y2="129.54" width="0.1524" layer="91"/>
<label x="167.64" y="129.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="P$2"/>
<pinref part="LED2" gate="G$1" pin="C"/>
<wire x1="193.04" y1="63.5" x2="193.04" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="LED1" gate="G$1" pin="C"/>
<pinref part="R2" gate="G$1" pin="P$2"/>
<wire x1="170.18" y1="63.5" x2="170.18" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="P0_5" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="P0_5"/>
<wire x1="127" y1="121.92" x2="132.08" y2="121.92" width="0.1524" layer="91"/>
<label x="132.08" y="121.92" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED1" gate="G$1" pin="A"/>
<wire x1="170.18" y1="71.12" x2="170.18" y2="76.2" width="0.1524" layer="91"/>
<label x="170.18" y="76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="P0_6" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="P0_6"/>
<wire x1="127" y1="119.38" x2="132.08" y2="119.38" width="0.1524" layer="91"/>
<label x="132.08" y="119.38" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="LED2" gate="G$1" pin="A"/>
<wire x1="193.04" y1="71.12" x2="193.04" y2="76.2" width="0.1524" layer="91"/>
<label x="193.04" y="76.2" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
