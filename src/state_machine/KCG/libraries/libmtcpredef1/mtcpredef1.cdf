<?xml version="1.0" encoding="ISO-8859-1"?>
<CriterionFile>
	<model>
		<Model>
			<operators>
				<Operator index="1" name="MTC1::CASE1_MTC_OBS"/>
				<Operator index="2" name="MTC1::IFTHENELSE_MTC_OBS"/>
				<Operator index="3" name="MTC1::CASE2_MTC_OBS"/>
				<Operator index="4" name="MTC1::NEQ_MTC_OBS"/>
				<Operator index="5" name="MTC1::INIT_MTC_OBS"/>
				<Operator index="6" name="MTC1::XOR_MTC_OBS"/>
				<Operator index="7" name="MTC1::WHEN_MTC_OBS"/>
				<Operator index="8" name="MTC1::SHARP_MTC_OBS"/>
				<Operator index="9" name="MTC1::OR_MTC_OBS"/>
				<Operator index="10" name="MTC1::NOT_MTC_OBS"/>
				<Operator index="11" name="MTC1::LTE_MTC_OBS"/>
				<Operator index="12" name="MTC1::LT_MTC_OBS"/>
				<Operator index="13" name="MTC1::GTE_MTC_OBS"/>
				<Operator index="14" name="MTC1::GT_MTC_OBS"/>
				<Operator index="15" name="MTC1::FBY_MTC_OBS"/>
				<Operator index="16" name="MTC1::EQ_MTC_OBS"/>
				<Operator index="17" name="MTC1::AND_MTC_OBS"/>
				<Operator index="18" name="MTC1::TIMES_MTC_OBS"/>
				<Operator index="19" name="MTC1::ACTIVATE_MTC_OBS"/>
				<Operator index="20" name="MTC1::RESTART_MTC_OBS"/>
				<Operator index="21" name="MTC1::SIGNAL_MTC_OBS"/>
				<Operator index="22" name="MTC1::ACTIVATE_NOINIT_MTC_OBS"/>
				<Operator index="23" name="MTC1::CLOCKED_ACTIVATE_MTC_OBS"/>
				<Operator index="24" name="MTC1::MERGE_MTC_OBS"/>
				<Operator index="25" name="MTC1::MAPW_MTC_OBS"/>
				<Operator index="26" name="MTC1::MAPWI_MTC_OBS"/>
				<Operator index="27" name="MTC1::FOLDW_MTC_OBS"/>
				<Operator index="28" name="MTC1::FOLDWI_MTC_OBS"/>
				<Operator index="29" name="MTC1::PRJ_DYN_MTC_OBS"/>
				<Operator index="30" name="MTC1::CHG_ITH_MTC_OBS"/>
			</operators>
		</Model>
	</model>
	<criterions>
		<Criterion ident="DC" name="Operator DC" operator="1">
			<elements>
				<Element ident="MTC_CASE1" name="Case1" description="Value equals Case1"/>
				<Element ident="MTC_DEFAULT" name="Default" description="Value is not equal to any Case"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="2">
			<elements>
				<Element ident="MTC_T" name="True" description="Condition is TRUE"/>
				<Element ident="MTC_F" name="False" description="Condition is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="3">
			<elements>
				<Element ident="MTC_CASE1" name="Case1" description="Value equals Case1"/>
				<Element ident="MTC_CASE2" name="Case2" description="Value equals Case2"/>
				<Element ident="MTC_DEFAULT" name="Default" description="Value is not equal to any Case"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="4">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is different from Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is equal to Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="5">
			<elements>
				<Element ident="MTC_A" name="Activated" description="INIT is activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="6">
			<elements>
				<Element ident="MTC_T" name="True" description="XOR output is TRUE"/>
				<Element ident="MTC_F" name="False" description="XOR output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="7">
			<elements>
				<Element ident="MTC_A" name="Activated" description="WHEN is activated"/>
				<Element ident="MTC_NA" name="Not Activated" description="WHEN is not activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="8">
			<elements>
				<Element ident="MTC_T" name="True" description="SHARP output is TRUE"/>
				<Element ident="MTC_F" name="False" description="SHARP output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="9">
			<elements>
				<Element ident="MTC_T" name="True" description="OR output is TRUE"/>
				<Element ident="MTC_F" name="False" description="OR output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="10">
			<elements>
				<Element ident="MTC_T" name="True" description="NOT output is TRUE"/>
				<Element ident="MTC_F" name="False" description="NOT output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="11">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is less than or equal Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is strictly greater than Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="12">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is strictly less than Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is greater than or equal Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="13">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is greater than or equal Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is strictly less than Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="14">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is strictly greater than Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is less than or equal Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="15">
			<elements>
				<Element ident="MTC_A" name="Activated" description="FBY is activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="16">
			<elements>
				<Element ident="MTC_T" name="True" description="Input1 is equal to Input2"/>
				<Element ident="MTC_F" name="False" description="Input1 is different from Input2"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="17">
			<elements>
				<Element ident="MTC_T" name="True" description="AND output is TRUE"/>
				<Element ident="MTC_F" name="False" description="AND output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="18">
			<elements>
				<Element ident="MTC_T" name="True" description="TIMES output is TRUE"/>
				<Element ident="MTC_F" name="False" description="TIMES output is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="19">
			<elements>
				<Element ident="MTC_A" name="Activated" description="ACTIVATE is activated"/>
				<Element ident="MTC_NA" name="Not Activated" description="ACTIVATE is not activated"/>
				<Element ident="MTC_INIT" name="Init State" description="ACTIVATE is in init state"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="20">
			<elements>
				<Element ident="MTC_A" name="Activated" description="RESTART is activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="21">
			<elements>
				<Element ident="MTC_T" name="True" description="Signal is TRUE"/>
				<Element ident="MTC_F" name="False" description="Signal is FALSE"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="22">
			<elements>
				<Element ident="MTC_A" name="Activated" description="ACTIVATE is activated"/>
				<Element ident="MTC_NA" name="Not Activated" description="ACTIVATE is not activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="23">
			<elements>
				<Element ident="MTC_A" name="Activated" description="ACTIVATE is activated"/>
				<Element ident="MTC_NA" name="Not Activated" description="ACTIVATE is not activated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="24">
			<elements>
				<Element ident="MTC_T" name="True" description="Clock is true"/>
				<Element ident="MTC_F" name="False" description="Clock is false"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="25">
			<elements>
				<Element ident="MTC_NOT_ITER" name="No Iteration" description="MAPW is not iterated"/>
				<Element ident="MTC_PART_ITER" name="Partial Iteration" description="MAPW is partially iterated"/>
				<Element ident="MTC_ALL_ITER" name="Complete Iteration" description="MAPW is completely iterated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="26">
			<elements>
				<Element ident="MTC_NOT_ITER" name="No Iteration" description="MAPWI is not iterated"/>
				<Element ident="MTC_PART_ITER" name="Partial Iteration" description="MAPWI is partially iterated"/>
				<Element ident="MTC_ALL_ITER" name="Complete Iteration" description="MAPWI is completely iterated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="27">
			<elements>
				<Element ident="MTC_NOT_ITER" name="No Iteration" description="FOLDW is not iterated"/>
				<Element ident="MTC_PART_ITER" name="Partial Iteration" description="FOLDW is partially iterated"/>
				<Element ident="MTC_ALL_ITER" name="Complete Iteration" description="FOLDW is completely iterated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="28">
			<elements>
				<Element ident="MTC_NOT_ITER" name="No Iteration" description="FOLDWI is not iterated"/>
				<Element ident="MTC_PART_ITER" name="Partial Iteration" description="FOLDWI is partially iterated"/>
				<Element ident="MTC_ALL_ITER" name="Complete Iteration" description="FOLDWI is completely iterated"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="29">
			<elements>
				<Element ident="MTC_IN_RANGE" name="In Range" description="The index is in range"/>
				<Element ident="MTC_OUT_OF_RANGE" name="Out of Range" description="The index is out of range"/>
			</elements>
		</Criterion>
		<Criterion ident="DC" name="Operator DC" operator="30">
			<elements>
				<Element ident="MTC_IN_RANGE" name="In Range" description="The index is in range"/>
				<Element ident="MTC_OUT_OF_RANGE" name="Out of Range" description="The index is out of range"/>
			</elements>
		</Criterion>
	</criterions>
</CriterionFile>
