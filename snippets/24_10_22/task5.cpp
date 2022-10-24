long long wow(AlienLifeForm form)
{
    unsigned int nameLength = 0u;
    while(form.name[nameLength] != '\0')
        ++nameLength;
    long long const wow0 = form.sentient
        ?     126ll * nameLength
            -   2ll * form.weight
            +   5ll * form.length
            -   5ll * form.speed
            +  97ll * form.tentacles
            +   4ll * form.color[0]
            +   4ll * form.color[1]
            +  30ll * form.color[2]
            + 138ll * form.color[3]
        :      23ll * nameLength
            +  52ll * form.weight * form.speed
            +  27ll * form.length
            +   5ll * form.tentacles
            +  75ll * form.color[0]
            +   2ll * form.color[1]
            -  27ll * form.color[3];
    return form.carnivore
        ? wow0 * 5
        : wow0 / 3;
}
int compare (AlienLifeForm a, AlienLifeForm b)
{
    long long const wa = wow(a);
    long long const wb = wow(b);
    return wa == wb
        ? 0
        : (wa > wb ? 1 : -1);
}
