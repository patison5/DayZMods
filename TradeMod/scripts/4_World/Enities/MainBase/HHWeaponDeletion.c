// ref HHWeaponDeletion hh_weaponDeletion;

// ref HHWeaponDeletion GetWeaponDeletion() {
// 	if (!hh_weaponDeletion)
// 		hh_weaponDeletion = new ref HHWeaponDeletion();	

// 	return hh_weaponDeletion;
// }


// class HHWeaponDeletion
// {
// 	ref array<EntityAI> entities = new array<EntityAI>;

// 	ref array<EntityAI> GetEntities() {
// 		return entities;
// 	}

// 	void addEntity (EntityAI ent) {
// 		entities.Insert(ent);

// 		Print("Added entity" + this.entities.Count());
// 	}

// 	void checkAndRemove() {
// 		foreach (auto ent : entities) {
//         	if (ent.GetHierarchyRootPlayer() == null)
//         		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.removeItem, 2000, false, ent);
//         }
// 	}

// 	void removeItem(EntityAI entity)
//     {
//         if (entity.GetHierarchyRootPlayer() == null) {
//             GetGame().ObjectDelete(entity);
//             // entities.Remove(entity);
//         }
//     }
// }