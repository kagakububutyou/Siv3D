#pragma once

class Noncopyable
{
private:
	Noncopyable() = default;
	Noncopyable(const Noncopyable&) = default;
	Noncopyable &operator=(const Noncopyable&) = default;
};