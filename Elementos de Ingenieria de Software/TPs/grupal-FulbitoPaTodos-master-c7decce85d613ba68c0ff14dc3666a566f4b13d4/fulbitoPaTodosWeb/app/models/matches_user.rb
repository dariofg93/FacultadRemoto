class MatchesUser < ApplicationRecord
    belongs_to :match
    belongs_to :user

    def self.create_with_ids(match_id, user_id)
        MatchesUser.create!(:match_id => match_id, :user_id => user_id)
    end

    # une un usuario a un partido si el usuario no tiene compromisos con
    # partidos exclusivos
    def self.create_if_not_exclusive(match_id, user_id)
        match = Match.find(match_id)
        exclusive = false
        MatchesUser.where(:user_id => user_id).each do |mm|
            m = Match.where(["id = ? AND time = ?", mm.id, match.time]).first
            if m != nil
              exclusive = exclusive or m.exclusive
            end
        end
        if exclusive || match.exclusive
            return "No te puedes unir a dos partidos en el mismo horario!"
        else
            MatchesUser.create_with_ids(match_id, user_id)
            return "Te Uniste Al Partido!"
        end
    end
end
