#pragma once

#ifndef PHANTASMA_SHA256
#error "You must supply a SHA256 implementation"
#endif

namespace phantasma {

void SHA256( Byte* output, int outputSize, const Byte* input, int inputSize )
{
	if(!output || !input || outputSize != 32 || inputSize < 0 )
	{
		PHANTASMA_EXCEPTION("Invalid arguments");
		return;
	}
	PHANTASMA_SHA256(output, outputSize, input, inputSize);
}

ByteArray SHA256( const ByteArray& input )
{
	ByteArray result;
	result.resize(32);
	SHA256(&result.front(), 32, input.empty() ? 0 : &input.front(), (int)input.size());
	return result;
}

}
