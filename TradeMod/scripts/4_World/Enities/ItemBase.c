// Очистка карты от вещей
// -- удаление вещей при спавне на земле
// -- удаление вещей спустя 10с в случае, если кто-то скинул их на землю или обранил при смерти
modded class ItemBase 
{
	void removeItem(ItemBase entity)
    {	
        if (entity.GetHierarchyRootPlayer() == null) {
            GetGame().ObjectDelete(entity);
        }
    }

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner) {
		super.OnItemLocationChanged(old_owner, new_owner);

		if (GetGame().IsServer()) {
			if ((old_owner == null) && (new_owner == null)) {
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.removeItem, 1000, false, this);
			} else if (new_owner == null) {
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.removeItem, 10000, false, this);
			}
		}
	}
}