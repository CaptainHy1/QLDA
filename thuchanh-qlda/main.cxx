#include <cassert>
#include <cstdio>

#include "vector.hh"

int main(void)
{
        FloatVector troll, bachkhoa;
        for (int i=0; i<5; i++) {
                troll.push(i);
                bachkhoa.push(i*2);
        }

        assert(troll.pop() == 4);
        assert(bachkhoa.pop() == 8);

        assert(troll != bachkhoa);

        troll = troll * 2;
        assert(troll == bachkhoa);

        bachkhoa = bachkhoa + 1;
        troll = troll + 1;
        assert(troll == bachkhoa);

        printf("Da pass moi test. Chuc mung cac\n");
        printf("thanh vien da duoc 1 diem cong.\n");

        return 0;
}

