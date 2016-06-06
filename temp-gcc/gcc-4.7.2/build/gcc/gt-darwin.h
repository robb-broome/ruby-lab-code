/* Type information for config/darwin.c.
   Copyright (C) 2004, 2007, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* This file is machine generated.  Do not edit.  */

void
gt_ggc_mx_cfstring_descriptor (void *x_p)
{
  struct cfstring_descriptor * const x = (struct cfstring_descriptor *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_9tree_node ((*x).literal);
      gt_ggc_m_9tree_node ((*x).constructor);
    }
}

void
gt_ggc_mx_VEC_dwarf_sect_used_entry_gc (void *x_p)
{
  struct VEC_dwarf_sect_used_entry_gc * const x = (struct VEC_dwarf_sect_used_entry_gc *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      {
        size_t i0;
        size_t l0 = (size_t)(((*x).base).prefix.num);
        for (i0 = 0; i0 != l0; i0++) {
          gt_ggc_m_S ((*x).base.vec[i0].name);
        }
      }
    }
}

void
gt_ggc_mx_VEC_darwin_lto_section_e_gc (void *x_p)
{
  struct VEC_darwin_lto_section_e_gc * const x = (struct VEC_darwin_lto_section_e_gc *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      {
        size_t i0;
        size_t l0 = (size_t)(((*x).base).prefix.num);
        for (i0 = 0; i0 != l0; i0++) {
          gt_ggc_m_S ((*x).base.vec[i0].sectname);
        }
      }
    }
}

void
gt_ggc_mx_machopic_indirection (void *x_p)
{
  struct machopic_indirection * const x = (struct machopic_indirection *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      gt_ggc_m_7rtx_def ((*x).symbol);
      gt_ggc_m_S ((*x).ptr_name);
    }
}

void
gt_ggc_m_P19cfstring_descriptor4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_19cfstring_descriptor ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_ggc_m_P20machopic_indirection4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (ggc_test_and_set_mark (x))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_ggc_m_20machopic_indirection ((*x).entries[i0]);
        }
        ggc_mark ((*x).entries);
      }
    }
}

void
gt_pch_nx_cfstring_descriptor (void *x_p)
{
  struct cfstring_descriptor * const x = (struct cfstring_descriptor *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_19cfstring_descriptor, gt_ggc_e_19cfstring_descriptor))
    {
      gt_pch_n_9tree_node ((*x).literal);
      gt_pch_n_9tree_node ((*x).constructor);
    }
}

void
gt_pch_nx_VEC_dwarf_sect_used_entry_gc (void *x_p)
{
  struct VEC_dwarf_sect_used_entry_gc * const x = (struct VEC_dwarf_sect_used_entry_gc *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_28VEC_dwarf_sect_used_entry_gc, gt_ggc_e_28VEC_dwarf_sect_used_entry_gc))
    {
      {
        size_t i0;
        size_t l0 = (size_t)(((*x).base).prefix.num);
        for (i0 = 0; i0 != l0; i0++) {
          gt_pch_n_S ((*x).base.vec[i0].name);
        }
      }
    }
}

void
gt_pch_nx_VEC_darwin_lto_section_e_gc (void *x_p)
{
  struct VEC_darwin_lto_section_e_gc * const x = (struct VEC_darwin_lto_section_e_gc *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_27VEC_darwin_lto_section_e_gc, gt_ggc_e_27VEC_darwin_lto_section_e_gc))
    {
      {
        size_t i0;
        size_t l0 = (size_t)(((*x).base).prefix.num);
        for (i0 = 0; i0 != l0; i0++) {
          gt_pch_n_S ((*x).base.vec[i0].sectname);
        }
      }
    }
}

void
gt_pch_nx_machopic_indirection (void *x_p)
{
  struct machopic_indirection * const x = (struct machopic_indirection *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_20machopic_indirection, gt_ggc_e_20machopic_indirection))
    {
      gt_pch_n_7rtx_def ((*x).symbol);
      gt_pch_n_S ((*x).ptr_name);
    }
}

void
gt_pch_n_P19cfstring_descriptor4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P19cfstring_descriptor4htab, gt_types_enum_last))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_19cfstring_descriptor ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P19cfstring_descriptor4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_n_P20machopic_indirection4htab (void *x_p)
{
  struct htab * const x = (struct htab *)x_p;
  if (gt_pch_note_object (x, x, gt_pch_p_P20machopic_indirection4htab, gt_types_enum_last))
    {
      if ((*x).entries != NULL) {
        size_t i0;
        for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
          gt_pch_n_20machopic_indirection ((*x).entries[i0]);
        }
        gt_pch_note_object ((*x).entries, x, gt_pch_p_P20machopic_indirection4htab, gt_types_enum_last);
      }
    }
}

void
gt_pch_p_19cfstring_descriptor (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct cfstring_descriptor * const x ATTRIBUTE_UNUSED = (struct cfstring_descriptor *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).literal), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).constructor), cookie);
}

void
gt_pch_p_28VEC_dwarf_sect_used_entry_gc (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct VEC_dwarf_sect_used_entry_gc * const x ATTRIBUTE_UNUSED = (struct VEC_dwarf_sect_used_entry_gc *)x_p;
  {
    size_t i0;
    size_t l0 = (size_t)(((*x).base).prefix.num);
    for (i0 = 0; i0 != l0; i0++) {
      if ((void *)(x) == this_obj)
        op (&((*x).base.vec[i0].name), cookie);
    }
  }
}

void
gt_pch_p_27VEC_darwin_lto_section_e_gc (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct VEC_darwin_lto_section_e_gc * const x ATTRIBUTE_UNUSED = (struct VEC_darwin_lto_section_e_gc *)x_p;
  {
    size_t i0;
    size_t l0 = (size_t)(((*x).base).prefix.num);
    for (i0 = 0; i0 != l0; i0++) {
      if ((void *)(x) == this_obj)
        op (&((*x).base.vec[i0].sectname), cookie);
    }
  }
}

void
gt_pch_p_20machopic_indirection (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct machopic_indirection * const x ATTRIBUTE_UNUSED = (struct machopic_indirection *)x_p;
  if ((void *)(x) == this_obj)
    op (&((*x).symbol), cookie);
  if ((void *)(x) == this_obj)
    op (&((*x).ptr_name), cookie);
}

void
gt_pch_p_P19cfstring_descriptor4htab (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct htab * const x ATTRIBUTE_UNUSED = (struct htab *)x_p;
  if ((*x).entries != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
      if ((void *)((*x).entries) == this_obj)
        op (&((*x).entries[i0]), cookie);
    }
    if ((void *)(x) == this_obj)
      op (&((*x).entries), cookie);
  }
}

void
gt_pch_p_P20machopic_indirection4htab (ATTRIBUTE_UNUSED void *this_obj,
	void *x_p,
	ATTRIBUTE_UNUSED gt_pointer_operator op,
	ATTRIBUTE_UNUSED void *cookie)
{
  struct htab * const x ATTRIBUTE_UNUSED = (struct htab *)x_p;
  if ((*x).entries != NULL) {
    size_t i0;
    for (i0 = 0; i0 != (size_t)(((*x)).size); i0++) {
      if ((void *)((*x).entries) == this_obj)
        op (&((*x).entries[i0]), cookie);
    }
    if ((void *)(x) == this_obj)
      op (&((*x).entries), cookie);
  }
}

/* GC roots.  */

EXPORTED_CONST struct ggc_root_tab gt_ggc_r_gt_darwin_h[] = {
  {
    &cfstring_htab,
    1,
    sizeof (cfstring_htab),
    &gt_ggc_m_P19cfstring_descriptor4htab,
    &gt_pch_n_P19cfstring_descriptor4htab
  },
  {
    &pcchar_type_node,
    1,
    sizeof (pcchar_type_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &pcint_type_node,
    1,
    sizeof (pcint_type_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &pccfstring_type_node,
    1,
    sizeof (pccfstring_type_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &ccfstring_type_node,
    1,
    sizeof (ccfstring_type_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &cfstring_type_node,
    1,
    sizeof (cfstring_type_node),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &cfstring_class_reference,
    1,
    sizeof (cfstring_class_reference),
    &gt_ggc_mx_tree_node,
    &gt_pch_nx_tree_node
  },
  {
    &dwarf_sect_names_table,
    1,
    sizeof (dwarf_sect_names_table),
    &gt_ggc_mx_VEC_dwarf_sect_used_entry_gc,
    &gt_pch_nx_VEC_dwarf_sect_used_entry_gc
  },
  {
    &lto_section_names,
    1,
    sizeof (lto_section_names),
    &gt_ggc_mx_VEC_darwin_lto_section_e_gc,
    &gt_pch_nx_VEC_darwin_lto_section_e_gc
  },
  {
    &machopic_indirections,
    1,
    sizeof (machopic_indirections),
    &gt_ggc_m_P20machopic_indirection4htab,
    &gt_pch_n_P20machopic_indirection4htab
  },
  {
    &function_base_func_name,
    1,
    sizeof (function_base_func_name),
    (gt_pointer_walker) &gt_ggc_m_S,
    (gt_pointer_walker) &gt_pch_n_S
  },
  LAST_GGC_ROOT_TAB
};

EXPORTED_CONST struct ggc_root_tab gt_pch_rs_gt_darwin_h[] = {
  { &except_table_label_num, 1, sizeof (except_table_label_num), NULL, NULL },
  { &current_pic_label_num, 1, sizeof (current_pic_label_num), NULL, NULL },
  LAST_GGC_ROOT_TAB
};

