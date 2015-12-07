<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.5.0">
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
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X04">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="0" y1="0.635" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-0.635" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-2.54" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="5.08" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-5.1562" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
</package>
<package name="1X04/90">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-5.715" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="6.985" y="-4.445" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PINHD4">
<wire x1="-6.35" y1="-5.08" x2="1.27" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="1.27" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="7.62" x2="-6.35" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="7.62" x2="-6.35" y2="-5.08" width="0.4064" layer="94"/>
<text x="-6.35" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X4" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD4" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X04">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="/90" package="1X04/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
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
<package name="C050-025X075">
<description>&lt;b&gt;Condensateur 2 pas&lt;/b&gt;&lt;p&gt;
boitier 2.5 x 7.5 mm&lt;br&gt;
empattement 5 mm&lt;p&gt;
valeur typique ~ 100 nF</description>
<wire x1="-0.3048" y1="0.635" x2="-0.3048" y2="0" width="0.3048" layer="21"/>
<wire x1="-0.3048" y1="0" x2="-0.3048" y2="-0.635" width="0.3048" layer="21"/>
<wire x1="-0.3048" y1="0" x2="-1.524" y2="0" width="0.1524" layer="21"/>
<wire x1="0.3302" y1="0.635" x2="0.3302" y2="0" width="0.3048" layer="21"/>
<wire x1="0.3302" y1="0" x2="0.3302" y2="-0.635" width="0.3048" layer="21"/>
<wire x1="0.3302" y1="0" x2="1.524" y2="0" width="0.1524" layer="21"/>
<wire x1="-3.683" y1="1.016" x2="-3.683" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-3.429" y1="-1.27" x2="3.429" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.683" y1="-1.016" x2="3.683" y2="1.016" width="0.1524" layer="21"/>
<wire x1="3.429" y1="1.27" x2="-3.429" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.429" y1="1.27" x2="3.683" y2="1.016" width="0.1524" layer="21" curve="-90"/>
<wire x1="3.429" y1="-1.27" x2="3.683" y2="-1.016" width="0.1524" layer="21" curve="90"/>
<wire x1="-3.683" y1="-1.016" x2="-3.429" y2="-1.27" width="0.1524" layer="21" curve="90"/>
<wire x1="-3.683" y1="1.016" x2="-3.429" y2="1.27" width="0.1524" layer="21" curve="-90"/>
<pad name="1" x="-2.54" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.4064" diameter="1.9304" shape="octagon"/>
<text x="-3.429" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.429" y="-2.794" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="C025-025X050">
<description>&lt;b&gt;Condensateur 1 pas&lt;/b&gt;&lt;p&gt;
boitier 2.5 x 5 mm&lt;br&gt;
empattement 2.5 mm&lt;p&gt;
valeur typique ~ pF</description>
<wire x1="-2.159" y1="1.27" x2="2.159" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.159" y1="-1.27" x2="-2.159" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.413" y1="1.016" x2="2.413" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-2.413" y1="1.016" x2="-2.413" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.159" y1="1.27" x2="2.413" y2="1.016" width="0.1524" layer="21" curve="-90"/>
<wire x1="-2.413" y1="1.016" x2="-2.159" y2="1.27" width="0.1524" layer="21" curve="-90"/>
<wire x1="2.159" y1="-1.27" x2="2.413" y2="-1.016" width="0.1524" layer="21" curve="90"/>
<wire x1="-2.413" y1="-1.016" x2="-2.159" y2="-1.27" width="0.1524" layer="21" curve="90"/>
<wire x1="0.762" y1="0" x2="0.381" y2="0" width="0.1524" layer="51"/>
<wire x1="0.381" y1="0" x2="0.254" y2="0" width="0.1524" layer="21"/>
<wire x1="0.254" y1="0" x2="0.254" y2="0.762" width="0.254" layer="21"/>
<wire x1="0.254" y1="0" x2="0.254" y2="-0.762" width="0.254" layer="21"/>
<wire x1="-0.254" y1="0.762" x2="-0.254" y2="0" width="0.254" layer="21"/>
<wire x1="-0.254" y1="0" x2="-0.254" y2="-0.762" width="0.254" layer="21"/>
<wire x1="-0.254" y1="0" x2="-0.381" y2="0" width="0.1524" layer="21"/>
<wire x1="-0.381" y1="0" x2="-0.762" y2="0" width="0.1524" layer="51"/>
<pad name="1" x="-1.27" y="0" drill="0.4064" diameter="1.6764" shape="octagon"/>
<pad name="2" x="1.27" y="0" drill="0.4064" diameter="1.6764" shape="octagon"/>
<text x="-2.286" y="1.524" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.286" y="-2.794" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
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
</packages>
<symbols>
<symbol name="C_">
<wire x1="0" y1="0" x2="0" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.032" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<text x="1.27" y="0.635" size="1.27" layer="95">&gt;NAME</text>
<text x="1.27" y="-3.81" size="1.27" layer="96">&gt;VALUE</text>
<rectangle x1="-2.032" y1="-1.016" x2="2.032" y2="-0.508" layer="94"/>
<rectangle x1="-2.032" y1="-2.032" x2="2.032" y2="-1.524" layer="94"/>
<pin name="P$1" x="0" y="2.54" visible="off" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="P$2" x="0" y="-5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="C_" prefix="C" uservalue="yes">
<gates>
<gate name="G$1" symbol="C_" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="2PAS" package="C050-025X075">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="1PAS" package="C025-025X050">
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
<device name="0805" package="R0805">
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
<library name="redbearlab">
<packages>
<package name="MOUNTED_ON_PINHEADS">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-8.89" y1="4.445" x2="-8.89" y2="5.715" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="5.715" x2="-8.255" y2="6.35" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="6.35" x2="-6.985" y2="6.35" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="6.35" x2="-6.35" y2="5.715" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="6.35" x2="-8.89" y2="6.985" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.89" y2="8.255" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="8.255" x2="-8.255" y2="8.89" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="8.89" x2="-6.985" y2="8.89" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="8.89" x2="-6.35" y2="8.255" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="8.255" x2="-6.35" y2="6.985" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.985" y2="6.35" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.89" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="3.175" x2="-8.255" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="3.81" x2="-6.985" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="3.81" x2="-6.35" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="3.175" x2="-6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.905" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="4.445" x2="-8.255" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="3.81" x2="-6.35" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="5.715" x2="-6.35" y2="4.445" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-3.175" x2="-8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="-8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-1.27" x2="-8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-0.635" x2="-8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="0.635" x2="-8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="1.27" x2="-6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="1.27" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-0.635" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="-3.81" x2="-6.985" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-3.175" x2="-8.255" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-3.81" x2="-6.35" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.905" x2="-6.35" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="9.525" x2="-8.89" y2="10.795" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="10.795" x2="-8.255" y2="11.43" width="0.1524" layer="21"/>
<wire x1="-8.255" y1="11.43" x2="-6.985" y2="11.43" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="11.43" x2="-6.35" y2="10.795" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="9.525" x2="-8.255" y2="8.89" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="8.89" x2="-6.35" y2="9.525" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="10.795" x2="-6.35" y2="9.525" width="0.1524" layer="21"/>
<pad name="VIN" x="-7.62" y="-2.54" drill="1.016" shape="long" rot="R180"/>
<pad name="GND" x="-7.62" y="0" drill="1.016" shape="long" rot="R180"/>
<pad name="A4" x="-7.62" y="2.54" drill="1.016" shape="long" rot="R180"/>
<pad name="A3" x="-7.62" y="5.08" drill="1.016" shape="long" rot="R180"/>
<pad name="SWDIO" x="-7.62" y="7.62" drill="1.016" shape="long" rot="R180"/>
<pad name="SWCLK" x="-7.62" y="10.16" drill="1.016" shape="long" rot="R180"/>
<text x="-9.4488" y="-3.8862" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-4.445" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-7.874" y1="7.366" x2="-7.366" y2="7.874" layer="51" rot="R90"/>
<rectangle x1="-7.874" y1="4.826" x2="-7.366" y2="5.334" layer="51"/>
<rectangle x1="-7.874" y1="2.286" x2="-7.366" y2="2.794" layer="51" rot="R180"/>
<rectangle x1="-7.874" y1="-0.254" x2="-7.366" y2="0.254" layer="51" rot="R90"/>
<rectangle x1="-7.874" y1="-2.794" x2="-7.366" y2="-2.286" layer="51" rot="R90"/>
<rectangle x1="-7.874" y1="9.906" x2="-7.366" y2="10.414" layer="51" rot="R90"/>
<wire x1="6.35" y1="4.445" x2="6.35" y2="5.715" width="0.1524" layer="21"/>
<wire x1="6.35" y1="5.715" x2="6.985" y2="6.35" width="0.1524" layer="21"/>
<wire x1="6.985" y1="6.35" x2="8.255" y2="6.35" width="0.1524" layer="21"/>
<wire x1="8.255" y1="6.35" x2="8.89" y2="5.715" width="0.1524" layer="21"/>
<wire x1="6.985" y1="6.35" x2="6.35" y2="6.985" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="8.255" width="0.1524" layer="21"/>
<wire x1="6.35" y1="8.255" x2="6.985" y2="8.89" width="0.1524" layer="21"/>
<wire x1="6.985" y1="8.89" x2="8.255" y2="8.89" width="0.1524" layer="21"/>
<wire x1="8.255" y1="8.89" x2="8.89" y2="8.255" width="0.1524" layer="21"/>
<wire x1="8.89" y1="8.255" x2="8.89" y2="6.985" width="0.1524" layer="21"/>
<wire x1="8.89" y1="6.985" x2="8.255" y2="6.35" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="6.35" y2="1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.905" x2="6.35" y2="3.175" width="0.1524" layer="21"/>
<wire x1="6.35" y1="3.175" x2="6.985" y2="3.81" width="0.1524" layer="21"/>
<wire x1="6.985" y1="3.81" x2="8.255" y2="3.81" width="0.1524" layer="21"/>
<wire x1="8.255" y1="3.81" x2="8.89" y2="3.175" width="0.1524" layer="21"/>
<wire x1="8.89" y1="3.175" x2="8.89" y2="1.905" width="0.1524" layer="21"/>
<wire x1="8.89" y1="1.905" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.35" y1="4.445" x2="6.985" y2="3.81" width="0.1524" layer="21"/>
<wire x1="8.255" y1="3.81" x2="8.89" y2="4.445" width="0.1524" layer="21"/>
<wire x1="8.89" y1="5.715" x2="8.89" y2="4.445" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-3.175" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-1.27" x2="8.89" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.27" x2="6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="6.985" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="1.27" x2="8.255" y2="1.27" width="0.1524" layer="21"/>
<wire x1="8.255" y1="1.27" x2="8.89" y2="0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="0.635" x2="8.89" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-0.635" x2="8.255" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-3.81" x2="8.255" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-3.175" x2="6.985" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="8.255" y1="-3.81" x2="8.89" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-1.905" x2="8.89" y2="-3.175" width="0.1524" layer="21"/>
<wire x1="6.35" y1="9.525" x2="6.35" y2="10.795" width="0.1524" layer="21"/>
<wire x1="6.35" y1="10.795" x2="6.985" y2="11.43" width="0.1524" layer="21"/>
<wire x1="6.985" y1="11.43" x2="8.255" y2="11.43" width="0.1524" layer="21"/>
<wire x1="8.255" y1="11.43" x2="8.89" y2="10.795" width="0.1524" layer="21"/>
<wire x1="6.35" y1="9.525" x2="6.985" y2="8.89" width="0.1524" layer="21"/>
<wire x1="8.255" y1="8.89" x2="8.89" y2="9.525" width="0.1524" layer="21"/>
<wire x1="8.89" y1="10.795" x2="8.89" y2="9.525" width="0.1524" layer="21"/>
<pad name="GND_BIS" x="7.62" y="-2.54" drill="1.016" shape="long" rot="R180"/>
<pad name="RTS" x="7.62" y="0" drill="1.016" shape="long" rot="R180"/>
<pad name="RX" x="7.62" y="2.54" drill="1.016" shape="long" rot="R180"/>
<pad name="TX" x="7.62" y="5.08" drill="1.016" shape="long" rot="R180"/>
<pad name="CTS" x="7.62" y="7.62" drill="1.016" shape="long" rot="R180"/>
<pad name="VDD" x="7.62" y="10.16" drill="1.016" shape="long" rot="R180"/>
<text x="5.7912" y="-3.8862" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="10.795" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="7.366" y1="7.366" x2="7.874" y2="7.874" layer="51" rot="R90"/>
<rectangle x1="7.366" y1="4.826" x2="7.874" y2="5.334" layer="51"/>
<rectangle x1="7.366" y1="2.286" x2="7.874" y2="2.794" layer="51" rot="R180"/>
<rectangle x1="7.366" y1="-0.254" x2="7.874" y2="0.254" layer="51" rot="R90"/>
<rectangle x1="7.366" y1="-2.794" x2="7.874" y2="-2.286" layer="51" rot="R90"/>
<rectangle x1="7.366" y1="9.906" x2="7.874" y2="10.414" layer="51" rot="R90"/>
<dimension x1="-7.62" y1="-2.54" x2="7.62" y2="-2.54" x3="0" y3="-6.35" textsize="1.27" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="BLE_NANO">
<pin name="SWCLK" x="-17.78" y="7.62" length="middle"/>
<pin name="SWDIO" x="-17.78" y="2.54" length="middle"/>
<pin name="A3" x="-17.78" y="-2.54" length="middle"/>
<pin name="A4" x="-17.78" y="-7.62" length="middle"/>
<pin name="GND" x="-17.78" y="-12.7" length="middle"/>
<pin name="VIN" x="-17.78" y="-17.78" length="middle"/>
<pin name="VDD" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="CTS" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="TX" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="RX" x="17.78" y="-7.62" length="middle" rot="R180"/>
<pin name="RTS" x="17.78" y="-12.7" length="middle" rot="R180"/>
<pin name="GND_BIS" x="17.78" y="-17.78" length="middle" rot="R180"/>
<wire x1="-12.7" y1="12.7" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="12.7" y2="-20.32" width="0.254" layer="94"/>
<wire x1="12.7" y1="-20.32" x2="-12.7" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-20.32" x2="-12.7" y2="12.7" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="BLE_NANO">
<gates>
<gate name="G$1" symbol="BLE_NANO" x="0" y="2.54"/>
</gates>
<devices>
<device name="" package="MOUNTED_ON_PINHEADS">
<connects>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="CTS" pad="CTS"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND_BIS" pad="GND_BIS"/>
<connect gate="G$1" pin="RTS" pad="RTS"/>
<connect gate="G$1" pin="RX" pad="RX"/>
<connect gate="G$1" pin="SWCLK" pad="SWCLK"/>
<connect gate="G$1" pin="SWDIO" pad="SWDIO"/>
<connect gate="G$1" pin="TX" pad="TX"/>
<connect gate="G$1" pin="VDD" pad="VDD"/>
<connect gate="G$1" pin="VIN" pad="VIN"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="lm1117">
<packages>
<package name="SOT230P696X180-4N">
<smd name="1" x="-3.2004" y="2.3114" dx="1.6002" dy="0.8382" layer="1"/>
<smd name="2" x="-3.2004" y="0" dx="1.6002" dy="0.8382" layer="1"/>
<smd name="3" x="-3.2004" y="-2.3114" dx="1.6002" dy="0.8382" layer="1"/>
<smd name="4" x="3.2004" y="0" dx="1.6002" dy="3.0988" layer="1"/>
<wire x1="-1.8542" y1="1.905" x2="-1.8542" y2="2.6924" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="2.6924" x2="-3.6576" y2="2.6924" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="2.6924" x2="-3.6576" y2="1.905" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="1.905" x2="-1.8542" y2="1.905" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-0.381" x2="-1.8542" y2="0.4064" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="0.4064" x2="-3.6576" y2="0.4064" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="0.4064" x2="-3.6576" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-0.381" x2="-1.8542" y2="-0.381" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-2.6924" x2="-1.8542" y2="-1.905" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-1.905" x2="-3.6576" y2="-1.905" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-1.905" x2="-3.6576" y2="-2.6924" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-2.6924" x2="-1.8542" y2="-2.6924" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="1.5494" x2="1.8542" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="-1.5494" x2="3.6576" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="3.6576" y1="-1.5494" x2="3.6576" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="3.6576" y1="1.5494" x2="1.8542" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="-3.3528" x2="1.8542" y2="-3.3528" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="-3.3528" x2="1.8542" y2="3.3528" width="0.1524" layer="51"/>
<wire x1="1.8542" y1="3.3528" x2="-1.8542" y2="3.3528" width="0.1524" layer="51"/>
<wire x1="-1.8542" y1="3.3528" x2="-1.8542" y2="-3.3528" width="0.1524" layer="51"/>
<text x="-4.0386" y="2.3368" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.8542" y1="-3.3528" x2="1.8542" y2="-3.3528" width="0.1524" layer="21"/>
<wire x1="1.8542" y1="-3.3528" x2="1.8542" y2="3.3528" width="0.1524" layer="21"/>
<wire x1="1.8542" y1="3.3528" x2="-1.8542" y2="3.3528" width="0.1524" layer="21"/>
<wire x1="-1.8542" y1="3.3528" x2="-1.8542" y2="-3.3528" width="0.1524" layer="21"/>
<text x="-4.0386" y="2.3368" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-4.6482" y="3.6068" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.461" y="-5.588" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="LM1117MP-1.8">
<pin name="VIN" x="-20.32" y="0" length="middle" direction="in"/>
<pin name="ADJ/GND" x="-20.32" y="-5.08" length="middle" direction="pas"/>
<pin name="VOUT_2" x="20.32" y="-2.54" length="middle" direction="out" rot="R180"/>
<pin name="VOUT" x="20.32" y="0" length="middle" direction="out" rot="R180"/>
<wire x1="-15.24" y1="5.08" x2="-15.24" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="-15.24" y1="-10.16" x2="15.24" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="5.08" width="0.4064" layer="94"/>
<wire x1="15.24" y1="5.08" x2="-15.24" y2="5.08" width="0.4064" layer="94"/>
<text x="-4.6228" y="6.4008" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.4864" y="-12.6746" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="LM1117MP-1.8" prefix="U">
<description>IC REG LDO 800MA 1.8V</description>
<gates>
<gate name="A" symbol="LM1117MP-1.8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT230P696X180-4N">
<connects>
<connect gate="A" pin="ADJ/GND" pad="1"/>
<connect gate="A" pin="VIN" pad="3"/>
<connect gate="A" pin="VOUT" pad="2"/>
<connect gate="A" pin="VOUT_2" pad="4"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="LM1117MP-1.8" constant="no"/>
<attribute name="OC_FARNELL" value="1469053" constant="no"/>
<attribute name="OC_NEWARK" value="41K3467" constant="no"/>
<attribute name="PACKAGE" value="SOT-223" constant="no"/>
<attribute name="SUPPLIER" value="National Semiconductor" constant="no"/>
</technology>
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
<part name="DRONE_SIDE" library="pinhead" deviceset="PINHD-1X4" device=""/>
<part name="C1" library="@Club_passif" deviceset="C_" device="0805" value="10uF"/>
<part name="C2" library="@Club_passif" deviceset="C_" device="0805" value="10uF"/>
<part name="U$2" library="redbearlab" deviceset="BLE_NANO" device=""/>
<part name="C3" library="@Club_passif" deviceset="C_" device="1206" value="1uF"/>
<part name="U1" library="lm1117" deviceset="LM1117MP-1.8" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="DRONE_SIDE" gate="A" x="0" y="73.66"/>
<instance part="C1" gate="G$1" x="43.18" y="83.82"/>
<instance part="C2" gate="G$1" x="99.06" y="83.82"/>
<instance part="U$2" gate="G$1" x="58.42" y="33.02"/>
<instance part="C3" gate="G$1" x="104.14" y="30.48"/>
<instance part="U1" gate="A" x="71.12" y="86.36"/>
</instances>
<busses>
</busses>
<nets>
<net name="12V_ALIM" class="0">
<segment>
<pinref part="DRONE_SIDE" gate="A" pin="1"/>
<wire x1="-2.54" y1="78.74" x2="-12.7" y2="78.74" width="0.1524" layer="91"/>
<label x="-25.4" y="78.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="VIN"/>
<wire x1="38.1" y1="86.36" x2="43.18" y2="86.36" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="P$1"/>
<wire x1="43.18" y1="86.36" x2="50.8" y2="86.36" width="0.1524" layer="91"/>
<junction x="43.18" y="86.36"/>
<label x="30.48" y="88.9" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND_ALIM" class="0">
<segment>
<pinref part="DRONE_SIDE" gate="A" pin="2"/>
<wire x1="-2.54" y1="76.2" x2="-12.7" y2="76.2" width="0.1524" layer="91"/>
<label x="-25.4" y="76.2" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="GND_BIS"/>
<label x="86.36" y="10.16" size="1.778" layer="95"/>
<wire x1="76.2" y1="15.24" x2="104.14" y2="15.24" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="P$2"/>
<wire x1="104.14" y1="15.24" x2="106.68" y2="15.24" width="0.1524" layer="91"/>
<wire x1="104.14" y1="25.4" x2="104.14" y2="15.24" width="0.1524" layer="91"/>
<junction x="104.14" y="15.24"/>
</segment>
<segment>
<pinref part="C1" gate="G$1" pin="P$2"/>
<pinref part="U1" gate="A" pin="ADJ/GND"/>
<wire x1="43.18" y1="78.74" x2="50.8" y2="78.74" width="0.1524" layer="91"/>
<wire x1="50.8" y1="78.74" x2="50.8" y2="81.28" width="0.1524" layer="91"/>
<wire x1="43.18" y1="78.74" x2="43.18" y2="68.58" width="0.1524" layer="91"/>
<junction x="43.18" y="78.74"/>
<wire x1="43.18" y1="68.58" x2="99.06" y2="68.58" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="P$2"/>
<wire x1="99.06" y1="68.58" x2="99.06" y2="78.74" width="0.1524" layer="91"/>
<wire x1="43.18" y1="78.74" x2="38.1" y2="78.74" width="0.1524" layer="91"/>
<label x="30.48" y="78.74" size="1.778" layer="95"/>
</segment>
</net>
<net name="TX_DRONE" class="0">
<segment>
<pinref part="DRONE_SIDE" gate="A" pin="3"/>
<wire x1="-2.54" y1="73.66" x2="-12.7" y2="73.66" width="0.1524" layer="91"/>
<label x="-25.4" y="73.66" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="RX"/>
<wire x1="76.2" y1="25.4" x2="83.82" y2="25.4" width="0.1524" layer="91"/>
<label x="86.36" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="RX_DRONE" class="0">
<segment>
<pinref part="DRONE_SIDE" gate="A" pin="4"/>
<wire x1="-2.54" y1="71.12" x2="-12.7" y2="71.12" width="0.1524" layer="91"/>
<label x="-25.4" y="71.12" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="TX"/>
<wire x1="76.2" y1="30.48" x2="83.82" y2="30.48" width="0.1524" layer="91"/>
<label x="86.36" y="30.48" size="1.778" layer="95"/>
</segment>
</net>
<net name="1_8V" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="VDD"/>
<label x="88.9" y="45.72" size="1.778" layer="95"/>
<wire x1="76.2" y1="40.64" x2="104.14" y2="40.64" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="P$1"/>
<wire x1="104.14" y1="40.64" x2="106.68" y2="40.64" width="0.1524" layer="91"/>
<wire x1="104.14" y1="33.02" x2="104.14" y2="40.64" width="0.1524" layer="91"/>
<junction x="104.14" y="40.64"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="VOUT_2"/>
<wire x1="91.44" y1="83.82" x2="93.98" y2="83.82" width="0.1524" layer="91"/>
<wire x1="93.98" y1="83.82" x2="93.98" y2="86.36" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="VOUT"/>
<wire x1="93.98" y1="86.36" x2="91.44" y2="86.36" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="P$1"/>
<wire x1="93.98" y1="86.36" x2="99.06" y2="86.36" width="0.1524" layer="91"/>
<junction x="93.98" y="86.36"/>
<wire x1="99.06" y1="86.36" x2="109.22" y2="86.36" width="0.1524" layer="91"/>
<junction x="99.06" y="86.36"/>
<label x="109.22" y="88.9" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
