/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Static Entry Point Tables
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <winpr/platform.h>
#include <winpr/wtsapi.h>
#include <freerdp/svc.h>

/* The 'entry' function pointers have variable arguments. */
WINPR_PRAGMA_DIAG_PUSH
WINPR_PRAGMA_DIAG_IGNORED_STRICT_PROTOTYPES

typedef UINT(VCAPITYPE* static_entry_fn_t)();
typedef struct
{
	const char* name;
	static_entry_fn_t entry;
} STATIC_ENTRY;

typedef struct
{
	const char* name;
	const STATIC_ENTRY* table;
} STATIC_ENTRY_TABLE;

typedef UINT(VCAPITYPE* static_subsystem_entry_fn_t)();
typedef struct
{
	const char* name;
	const char* type;
	static_subsystem_entry_fn_t entry;
} STATIC_SUBSYSTEM_ENTRY;

typedef UINT(VCAPITYPE* static_addin_entry_fn_t)();
typedef struct
{
	const char* name;
	const char* type;
	static_addin_entry_fn_t entry;
	const STATIC_SUBSYSTEM_ENTRY* table;
} STATIC_ADDIN_TABLE;

WINPR_PRAGMA_DIAG_POP
