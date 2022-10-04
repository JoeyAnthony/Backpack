#pragma once

#include <EASTL/hash_map.h>;
#include <string>
#include <typeinfo>;

#include "backpack/core/hashing.h"

namespace backpack {
	class BP_IWorldObject {
	public:
		BP_IWorldObject();
		~BP_IWorldObject();

		const uint64_t& getId() { return id; };

	private:
		uint64_t id;

	public:
		std::string name;
	};

	class BP_IComponent {
	public:
		BP_IComponent(uint64_t id, uint64_t world_object_id, std::string name);

		const uint64_t& getId() { return id; };
		const uint64_t& get_world_object_Id() { return world_object_id; };

	private:
		uint64_t id;
		uint64_t world_object_id;

	public:
		std::string name;
	};

	class BP_World {
	public:
		BP_World() {
			
		}

		BP_IWorldObject* CreateWorldObject(std::string name);
		void DestroyWorldObject(uint64_t id);
		uint64_t CreateComponent(BP_IWorldObject* world_object, std::string name);
		void DestroyComponent(uint64_t id);

	private:

	public:
		void InitWorld();
		void UpdateWorld(float delta_time);

	private:
		eastl::hash_map<uint64_t, BP_IWorldObject*> active_objects;
		eastl::hash_map<uint64_t, BP_IComponent*> active_components;

		UniqueNumber world_objects_id_counter;
		UniqueNumber component_id_counter;
	};
}