// generated by lv2ttl2c from
// http://gareus.org/oss/lv2/sisco#4chan

extern const LV2_Descriptor* lv2_descriptor(uint32_t index);
extern const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index);

static const RtkLv2Description _plugin = {
	&lv2_descriptor,
	&lv2ui_descriptor
	, 6 // uint32_t dsp_descriptor_id
	, 0 // uint32_t gui_descriptor_id
	, "Simple Scope (4 channel)" // const char *plugin_human_id
	, (const struct LV2Port[10])
	{
		{ "control", ATOM_IN, nan, nan, nan, "GUI to plugin communication"},
		{ "notify", ATOM_OUT, nan, nan, nan, "Plugin to GUI communication"},
		{ "in1", AUDIO_IN, nan, nan, nan, "Channel 1 input"},
		{ "out1", AUDIO_OUT, nan, nan, nan, "signal pass-thru"},
		{ "in2", AUDIO_IN, nan, nan, nan, "Channel 2 input"},
		{ "out2", AUDIO_OUT, nan, nan, nan, "signal pass-thru"},
		{ "in3", AUDIO_IN, nan, nan, nan, "Channel 3 input"},
		{ "out3", AUDIO_OUT, nan, nan, nan, "signal pass-thru"},
		{ "in4", AUDIO_IN, nan, nan, nan, "Channel 4 input"},
		{ "out4", AUDIO_OUT, nan, nan, nan, "signal pass-thru"},
	}
	, 10 // uint32_t nports_total
	, 4 // uint32_t nports_audio_in
	, 4 // uint32_t nports_audio_out
	, 0 // uint32_t nports_midi_in
	, 0 // uint32_t nports_midi_out
	, 1 // uint32_t nports_atom_in
	, 1 // uint32_t nports_atom_out
	, 0 // uint32_t nports_ctrl
	, 0 // uint32_t nports_ctrl_in
	, 0 // uint32_t nports_ctrl_out
	, 131680 // uint32_t min_atom_bufsiz
	, false // bool send_time_info
	, UINT32_MAX // uint32_t latency_ctrl_port
};