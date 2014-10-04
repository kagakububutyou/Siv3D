/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once

class Noncopyable
{
private:
	Noncopyable() = default;
	Noncopyable(const Noncopyable&) = default;
	Noncopyable &operator=(const Noncopyable&) = default;
};