#ifndef MARK_8e4c7147_43c7_404f_8741_eebfda2d8717
#define MARK_8e4c7147_43c7_404f_8741_eebfda2d8717
/* Internal: hash tables (void *, int) -> void *
 * 
 * init() returns a fresh hash table or NULL if not enough memory/
 * fini() returns NULL.
 * extend() returns 0 on success, 1 if not enough memory or the key exists.
 * lookup() returns the value corresponding to the key. Missing keys return 0.
 *
 * This is a treap table, for details see
 *  Seidel, Raimund & Cecilia R. Aragon (1996), "Randomized Search Trees",
 *     Algorithmica 16 (4/5): pp. 464-497
 */
struct AffHash_s;

struct AffHash_s *aff_h_init(void);
void *aff_h_fini(struct AffHash_s *h);
void *aff_h_lookup(const struct AffHash_s *h, const void *key, int ksize);
int aff_h_extend(struct AffHash_s *h, const void *key, int ksize, void *data);
void aff_h_print(struct AffHash_s *h, int (*get_vsize)(const void *));

#endif /* !defined(MARK_8e4c7147_43c7_404f_8741_eebfda2d8717) */
