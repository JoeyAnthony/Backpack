#include "world.h"

namespace backpack {
	BP_IWorldObject::BP_IWorldObject() : name("") {

	}

	BP_IWorldObject* BP_World::CreateWorldObject(std::string name = "")
	{
		BP_IWorldObject* obj = new BP_IWorldObject();
		uint64_t id = world_objects_id_counter.GetNewId();
		active_objects[id] = obj;
		obj->name = name;
		return obj;
	}

	void BP_World::DestroyWorldObject(uint64_t id)
	{
		active_components.erase(id);
	}
	
	uint64_t BP_World::CreateComponent(BP_IWorldObject* world_object, std::string name = "")
	{
		uint64_t id = component_id_counter.GetNewId();
		BP_IComponent* comp = new BP_IComponent(id, world_object->getId(), name);
		active_components[id] = comp;
		return id;
	}

	void BP_World::DestroyComponent(uint64_t id)
	{
	}

	void BP_World::UpdateWorld(float delta_time)
	{
	}

	BP_IComponent::BP_IComponent(uint64_t id, uint64_t world_object_id, std::string name): id(id), world_object_id(world_object_id), name(name)
	{
	}
}
