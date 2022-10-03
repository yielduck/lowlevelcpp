std::uint32_t unsafeBitCast(float const f)
{
    return *reinterpret_cast<std::uint32_t const *>(&f);
}
