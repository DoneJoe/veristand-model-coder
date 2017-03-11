/* INPUT: *inData, pointer to inport data at the current timestamp, to be 
  	      consumed by the function
   OUTPUT: *outData, pointer to outport data at current time + baserate, to be
  	       produced by the function
   INPUT: timestamp, current simulation time */
int32_t USER_TakeOneStep(double *inData, double *outData, double timestamp) 
{
	if (inData) rtInport.In1 = inData[0];

	rtSignal.sinewave = sin(readParam.Freq * timestamp + readParam.Phase) * readParam.Amp + readParam.Bias;
	rtSignal.sum = rtInport.In1 + rtSignal.sinewave;
	rtSignal.gain = rtSignal.sum * readParam.Gain;
	rtOutport.Out1 = rtSignal.gain;			

	if (outData) outData[0] = rtOutport.Out1;	
	
	return NI_OK;
}