/** 
* @file sound.cpp 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#include "sound.h"
Sound snd;

Sound::Sound()
{
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 512;


	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) 
	{
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}

	three = Mix_LoadWAV("sounds\\three.wav");
	water = Mix_LoadWAV("sounds\\water.wav");
	hole = Mix_LoadWAV("sounds\\hole.wav");
	putter = Mix_LoadWAV("sounds\\putter.wav");
	driver = Mix_LoadWAV("sounds\\driver.wav");
}

Sound::~Sound()
{
	Mix_FreeChunk(three);
	Mix_FreeChunk(water); 
	Mix_FreeChunk(hole);
	Mix_FreeChunk(putter);
	Mix_FreeChunk(driver);
	Mix_CloseAudio();
}

const void Sound::Load(std::string file)
{
	if( file.empty() || !Mix_LoadWAV(file.c_str()) )
	{
		fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
		return;
	}
	else
	{
		Add(Mix_LoadWAV(file.c_str()));
	}
}

const void Sound::Add(Mix_Chunk* soundeffect)
{
	if(soundeffect)
	VChunk.push_back(*soundeffect);
}

const void Sound::Play(int id)
{
	if(VChunk.empty())
	{
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
		return;
	}
	if( id < VChunk.size()-1 || id > VChunk.size()-1 )
	{
		fprintf(stderr, "Unable to play WAV file: %s unknown file id\n", Mix_GetError());
		return;
	}
	int channel = Mix_PlayChannel(-1, &VChunk.at(id), 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}

const void Sound::Three()
{
	cout << "Trees are green and the red roses too...." << endl;
	int channel = Mix_PlayChannel(-1, three, 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}
const void Sound::Water()
{
	cout << "Water is wet and the rain too...." << endl;
	int channel = Mix_PlayChannel(-1, water, 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}
const void Sound::Hole()
{
	cout << "ohhh yeaaa you pocketed the ball...." << endl;
	int channel = Mix_PlayChannel(-1, hole, 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}
const void Sound::Putter()
{
	cout << "Using my little putter here...." << endl;
	int channel = Mix_PlayChannel(-1, putter, 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}
const void Sound::Driver()
{
	cout << "Hey! was that my driver making noise???" << endl;
	int channel = Mix_PlayChannel(-1, driver, 0);
	if(channel == -1) 
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
}