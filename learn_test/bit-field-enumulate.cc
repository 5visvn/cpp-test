
union masks {
   struct {
      unsigned int mask1 : 1;
      unsigned int mask2 : 1;
      unsigned int mask3 : 5;
      unsigned int : 25;
   } masked;
   unsigned int masks_value;
}
